// 服务端

// 建立逻辑:
// 建立socket
// 声明自身的端口号和地址并绑定到socket
// 使用listen打开监听
// 不断用accept查看是否有连接
// 有连接时(客户端发送连接请求) 捕获socket
// 使用recv获取消息的内容
// 通信完成后使用closeSocket关闭这个对应accept到的socket
// 若不仔需要等待任何客户端连接 使用closeSocket关闭自身的socket

// 编程过程:
// 1 加载套接字库 创建套接字 WSAStartup() && socket()
// p.s WSA(Web Server API)
// 2 绑定套接字到 一个IP地址 和 一个端口上 bind()
// 3 将套接字设置为监听模式等待连接请求 lisent()
// 4 请求到来后 接受连接请求 返回一个新的对应于此次连接的套接字 accept()
// 5 用返回的套接字和客户端进行通信 send() && recv()
// 6 返回 等待另一个连接请求
// 7 关闭套接字 关闭加载的套接字库 closesocket() && WSACleanup()

#include <iostream>
#include <stdio.h>
#include <winsock2.h>
using namespace std;

int RecvBits = 1024;

int main(int argc, char const *argv[])
{
	// 初始化WSA 加载winsock库
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if(0 != WSAStartup(sockVersion, &wsaData)){
		printf("WSAInit error\n");
		return 0;
	}

	// 创建套接字
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(INVALID_SOCKET == slisten){
		printf("socket error\n");
		return 0;
	}

	// 绑定IP和端口
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(1234);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if(SOCKET_ERROR == bind(slisten, (LPSOCKADDR)&sin, sizeof(sin))){
		printf("bind error\n");
		closesocket(slisten);
		return 0;
	}

	// 开始监听
	if(SOCKET_ERROR == listen(slisten, 5)){
		printf("lisent error\n");
		return 0;
	}

	// 循环接收数据
	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	char revData[RecvBits];
	while(true){
		printf("waiting for connection\n");
		sClient = accept(slisten, (SOCKADDR*)&remoteAddr, &nAddrlen);
		if(INVALID_SOCKET == sClient){
			printf("accept error\n");
			continue;
		}
		printf("accepted a connection: %s\n", inet_ntoa(remoteAddr.sin_addr));
		
		// 接收数据
		int ret = recv(sClient, revData, RecvBits, 0);
		if(ret > 0){
			revData[ret] = 0x00;
			printf("%s\n", revData);
		}
		
		// 发送数据
		const char* sendData = "hello Client from Server!";
		send(sClient, sendData, strlen(sendData), 0);
		closesocket(sClient);
	}

	closesocket(slisten);
	WSACleanup();
	
	return 0;
}

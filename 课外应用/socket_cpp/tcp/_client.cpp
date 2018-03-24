// 客户端
// 建立逻辑:
// 建立socket
// 通过端口号和地址确定目标服务器
// 使用connect连接到服务器
// send发送消息 等待处理
// 通信完成后调用closeSocket关闭socket

// 编程过程
// 1 加载套接字库 创建套接字 WSAStartup() && socket()
// 2 向服务器发出连接请求 connect()
// 3 和服务器进行通信 send() && recv()
// 4 关闭套接字 关闭加载的套接字库 closesocket() && WSACleanup()

#include <winsock2.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int RecvBits = 1024;

int main(int argc, char const *argv[])
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if(0 != WSAStartup(sockVersion, &wsaData)){
		printf("WSAInit error\n");
		return 0;
	}

	// while(true){
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(INVALID_SOCKET == sclient){
			printf("invalid socket\n");
			return 0;
		}

		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;
		serAddr.sin_port = htons(1234);
		serAddr.sin_addr.S_un.S_addr = inet_addr("192.168.9.149");

		// 连接失败
		int error_time = 0;
		while(SOCKET_ERROR == connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr))){
			error_time++;
			if(error_time == 20){
				closesocket(sclient);
				return 0;
			}
			printf("connect error\n");
			Sleep(1);
			connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr));
		}

		const char* sendData = "hi Server from Client!";
		send(sclient, sendData, strlen(sendData), 0);

		char recData[RecvBits];
		int ret = recv(sclient, recData, RecvBits, 0);
		if(ret > 0){
			recData[ret] = 0x00;
			printf("%s\n", recData);
		}

		closesocket(sclient);
	// }

	WSACleanup();

	return 0;
}

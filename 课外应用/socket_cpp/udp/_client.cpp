#include <stdio.h>
#include <winsock2.h>

#pragma coment(lib, "ws2_32.lib")

int recvBits = 1024;

int main(int argc, char const *argv[])
{
	WORD socketVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if(0 != WSAStartup(socketVersion, &wsaData))
		return 0;

	SOCKET sclient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(1234);
	sin.sin_addr.S_un.S_addr = inet_addr("192.168.9.149");
	int len = sizeof(sin);

	const char* sendData = "hi Server from client";
	sendto(sclient, sendData, strlen(sendData), 0, (sockaddr*)&sin, len);

	char recvData[recvBits];
	int ret = recvfrom(sclient, recvData, recvBits, 0, (sockaddr*)&sin, &len);
	if(0 <ret){
		recvData[ret] = 0x00;
		printf("%s\n", recvData);
	}

	closesocket(sclient);
	WSACleanup();
	
	return 0;
}

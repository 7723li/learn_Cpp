#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int recvBits = 1024;

int main(int argc, char const *argv[])
{
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 2);
	if(0 != WSAStartup(sockVersion, &wsaData)){
		printf("WSAInit error\n");
		return 0;
	}

	SOCKET serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(INVALID_SOCKET == serSocket){
		printf("socket error\n");
		return 0;
	}

	sockaddr_in serAddr;
	serAddr.sin_family  = AF_INET;
	serAddr.sin_port = htons(1234);
	serAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	if(SOCKET_ERROR == bind(serSocket, (sockaddr*)&serAddr, sizeof(serAddr))){
		printf("bind error\n");
		closesocket(serSocket);
		return 0;
	}

	sockaddr_in remoteAddr;
	int nAddLen = sizeof(remoteAddr);
	while(true){
		char recvData[recvBits];
		int ret = recvfrom(serSocket, recvData, recvBits, 0, (sockaddr*)&remoteAddr, &nAddLen);
		if(0 < ret){
			recvData[ret] = 0x00;
			printf("accept a connection from %s\n", inet_ntoa(remoteAddr.sin_addr));
			printf("%s\n", recvData);
		}

		const char* sendData = "hello Client from Server\n";
		sendto(serSocket, sendData, strlen(sendData), 0, (sockaddr*)&remoteAddr, nAddLen);
	}

	closesocket(serSocket);
	WSACleanup();
	
	return 0;
}

// WinSocketCpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows.h"
#include "iostream"
#pragma comment(lib,"ws2_32.lib")
//#include "WinSock2.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsaDATA;
	SOCKET ListeningSocket;
	SOCKADDR_IN ServerAddr;

	SOCKET NewConnection;
	SOCKADDR_IN ClientAddr;
	int Port =5150;
 	cout << WSAStartup(MAKEWORD(2,2),&wsaDATA) <<endl;

	ListeningSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); 

	ServerAddr.sin_family=AF_INET;
	ServerAddr.sin_port=htons(Port);
	ServerAddr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);

	bind(ListeningSocket,(SOCKADDR *)&ServerAddr,sizeof(ServerAddr));//SOCKADDR equal to SOCKADDR_IN

	listen(ListeningSocket,2);//backlog: max length of pending connections queue;

	int len=sizeof(ClientAddr);
	NewConnection=accept(ListeningSocket,(SOCKADDR *)&ClientAddr,&len);
	cout <<"client port:"<<ntohs(ClientAddr.sin_port)<<endl;


	NewConnection=accept(ListeningSocket,(SOCKADDR *)&ClientAddr,&len);
	cout <<"client port:"<<ntohs(ClientAddr.sin_port)<<endl;

	Sleep(20000);

	closesocket(NewConnection);
	closesocket(ListeningSocket);

	int a=16,b;
	b=htons(a);
	cout <<"a=  " <<a<<endl;
	cout <<"b=  " <<b<<endl;

	WSACleanup();

	char end;
	cin >> end;
	return 0;
}


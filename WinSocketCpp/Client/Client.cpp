// Client.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "WinSock2.h"
#include <iostream>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
        WSADATA                   wsaData;
        SOCKET                     s;
        SOCKADDR_IN          ServerAddr;
        int                                Port = 5150;   

        WSAStartup(MAKEWORD(2,2), &wsaData);                                               //��ʼ��Windows Socket 2.2      
        s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);                           // ����һ���µ�Socket�����ӷ�����  

       ServerAddr.sin_family = AF_INET;
       ServerAddr.sin_port = htons(Port);    
       ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");                                //�ڳ��������뱾������ͨ��

       int result = connect(s, (SOCKADDR *) &ServerAddr, sizeof(ServerAddr));   // �������������������
       if(result == 0){                                                                                                //result==0��ʾ���ӳɹ�
               cout << "Client has connected to server!";
			   Sleep(20000);
      }
       closesocket(s);
       WSACleanup();

	   char end;
	   cin >> end;
       return 0;
}


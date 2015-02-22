#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>

using namespace std;

SOCKADDR_IN addr;

SOCKET sListen;
SOCKET sConnect;
SOCKET* Connections;

int addrlen = sizeof(addr);
int ConCounter = 0;

struct Buffer
{
    int ID;
    char Message[256];
};

int ServerThread(int ID)
{
    Buffer sbuffer;

    char* Recv = new char[256];
    ZeroMemory(Recv, 256);

    char* Send = new char[sizeof(Buffer)];
    ZeroMemory(Send, sizeof(Buffer));

    for(;; Sleep(10))
    {
        if(recv(Connections[ID], Recv, 256, NULL))
        {
            sbuffer.ID = ID;
            memcpy(sbuffer.Message, Recv, 256);
            memcpy(Send, &sbuffer, sizeof(Buffer));

            for(int a = 0; a != ConCounter; a++)
            {
                if(Connections[a] == Connections[ID])
                {

                }
                else
                {
                    send(Connections[a], Send, sizeof(Buffer), NULL);
                }
            }
            ZeroMemory(Recv, 256);
        }
    }

    return 0;
}

int InitWinSock()
{
    int RetVal = 0;
    WSAData wsaData;
    WORD DllVersion = MAKEWORD(2,1);
    RetVal = WSAStartup(DllVersion, &wsaData);

    return RetVal;
}

int main()
{
    int RetVal = 0;
    RetVal = InitWinSock();
    if(RetVal != 0)
    {
        MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
        exit(1);
    }

    Connections = (SOCKET*)calloc(64, sizeof(SOCKET));

    sListen = socket(AF_INET, SOCK_STREAM, NULL);
    sConnect = socket(AF_INET, SOCK_STREAM, NULL);

    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port        = htons(1234);
    addr.sin_family      = AF_INET;

    bind(sListen, (SOCKADDR*)&addr, sizeof(addr));

    listen(sListen, 64);

    for(;; Sleep(50))
    {
        if(sConnect = accept(sListen, (SOCKADDR*)&addr, &addrlen))
        {
            Connections[ConCounter] = sConnect;

            char* ID = new char[64];
            ZeroMemory(ID, sizeof(ID));
            ID[2] = 'a';
            itoa(ConCounter, ID, 10);
            send(Connections[ConCounter], ID, sizeof(ID), NULL);

            ConCounter = ConCounter + 1;
            CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) ServerThread, (LPVOID)(ConCounter - 1), NULL, NULL);
        }
    }

    return 0;
}

#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <cstdio>
using namespace std;


SOCKADDR_IN addr;

SOCKET sConnect;

// For this we need to send two information at one time:
// 1. The main message
// 2. The ID

// To send more than one information I will use a struct
struct Buffer
{
    int ID;
    char Message[256];
};

int ClientThread()
{
    Buffer sbuffer;

    char buffer[sizeof(sbuffer)] = {0};

    for(;; Sleep(10))
    {
        // The server will send a struct to the client
        // containing message and ID
        // But send only accepts a char as buffer parameter
        // so here we need to recv a char buffer and then
        // we copy the content of this buffer to our struct
        if(recv(sConnect, buffer, sizeof(sbuffer), NULL))
        {
            memcpy(&sbuffer, buffer, sizeof(sbuffer));
            cout << "<Client " << sbuffer.ID << ":> " << sbuffer.Message <<endl;
        }
    }

    return 0;
}

int main()
{
    system("cls");

    int RetVal = 0;

    WSAData wsaData;
    WORD DllVersion = MAKEWORD(2,1);
    RetVal = WSAStartup(DllVersion, &wsaData);
    if(RetVal != 0)
    {
        MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
        exit(1);
    }

    sConnect = socket(AF_INET, SOCK_STREAM, NULL);

    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port        = htons(1234);
    addr.sin_family      = AF_INET;

    cout << "Connect to Masterserver? [ENTER]" <<endl;
    getchar();
    RetVal = connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));

    if(RetVal != 0)
    {
        MessageBoxA(NULL, "Could not connect to server", "Error", MB_OK | MB_ICONERROR);
        main();
    }
    else
    {
        int ID;
        char* cID = new char[64];
        ZeroMemory(cID, 64);

        recv(sConnect, cID, 64, NULL);
        ID = atoi(cID);

        cout << "Connected" <<endl;
        cout << "You are Client No: " << ID <<endl;

        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) ClientThread, NULL, NULL, NULL);

        for(;; Sleep(10))
        {
            char* buffer = new char[256];
            ZeroMemory(buffer, 256);
            cout << "send data";
            cin >> buffer;
            getchar();

            send(sConnect, buffer, 256, NULL);
        }
    }

    return 0;
}

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstring>

using namespace std;

int main(){

    //Initialize Winsock
    WSADATA wsaData;
    int wsaResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (wsaResult != 0) {
        cerr << "WSAStartup failed: " << wsaResult <<endl;
        return 1;
    }

    //Create a Socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    //Define server address structure
    sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);  // Server port
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //localhost

    //Connect to the server
    int connectResult = connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
    if (connectResult == SOCKET_ERROR) {
        cerr << "Connect failed: " << WSAGetLastError() << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "Connected to server" << endl;

    //Send the abbreviation
    string abbreviation; 
    cout<<"Enter the abbreviation of the STATE (Use caital letters): ";cin>>abbreviation;
    int bytesSent = send(clientSocket, abbreviation.c_str(), abbreviation.size(), 0);
    if (bytesSent == SOCKET_ERROR) {
        cerr << "Send failed: " << WSAGetLastError() << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Receive the server's response (state name or error message)
    char buffer[1024] = {0};
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived == SOCKET_ERROR) {
        cerr << "Recv failed: " << WSAGetLastError() << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "Received from server: " << buffer << endl;

    // Close the socket and cleanup Winsock
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
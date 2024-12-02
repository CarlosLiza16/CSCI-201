#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>  // For functions like inet_pton and sockaddr_in
#include <cstring>
#include <map>
#include <string>

using namespace std;

map<string, string> stateMap = {
    {"AL", "Alabama"}, {"AK", "Alaska"}, {"AZ", "Arizona"}, {"AR", "Arkansas"},
    {"CA", "California"}, {"CO", "Colorado"}, {"CT", "Connecticut"}, {"DE", "Delaware"},
    {"FL", "Florida"}, {"GA", "Georgia"}, {"HI", "Hawaii"}, {"ID", "Idaho"},
    {"IL", "Illinois"}, {"IN", "Indiana"}, {"IA", "Iowa"}, {"KS", "Kansas"},
    {"KY", "Kentucky"}, {"LA", "Louisiana"}, {"ME", "Maine"}, {"MD", "Maryland"},
    {"MA", "Massachusetts"}, {"MI", "Michigan"}, {"MN", "Minnesota"}, {"MS", "Mississippi"},
    {"MO", "Missouri"}, {"MT", "Montana"}, {"NE", "Nebraska"}, {"NV", "Nevada"},
    {"NH", "New Hampshire"}, {"NJ", "New Jersey"}, {"NM", "New Mexico"}, {"NY", "New York"},
    {"NC", "North Carolina"}, {"ND", "North Dakota"}, {"OH", "Ohio"}, {"OK", "Oklahoma"},
    {"OR", "Oregon"}, {"PA", "Pennsylvania"}, {"RI", "Rhode Island"}, {"SC", "South Carolina"},
    {"SD", "South Dakota"}, {"TN", "Tennessee"}, {"TX", "Texas"}, {"UT", "Utah"},
    {"VT", "Vermont"}, {"VA", "Virginia"}, {"WA", "Washington"}, {"WV", "West Virginia"},
    {"WI", "Wisconsin"}, {"WY", "Wyoming"}
};

int main(){

    // Initialize Winsock
    WSADATA wsaData;
    int wsaResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (wsaResult != 0) {
        cerr << "WSAStartup failed: " << wsaResult <<endl;
        return 1;
    }

    //Create a socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    //Define server address structure
    sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));  // Zero out the structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);            // Port number (in network byte order)
    serverAddr.sin_addr.s_addr = INADDR_ANY;      // Listen on all available network interfaces


    //Bind the server 
    if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Bind failed: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout<<"Socket bound successfully"<<endl;

    //Listen the connections
    if(listen(serverSocket, 5) == SOCKET_ERROR){
        cerr<<"Listen failed: " << WSAGetLastError() <<endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout<<"Waiting for client connections..."<<endl;


    //Accepting a CLiente Connection
    SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
    if(clientSocket == INVALID_SOCKET){
        cerr<< "Accept failed: "<< WSAGetLastError()<<endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Client connected" << endl;

    //Receiving Data from the client
    char buffer[3] = {0}; //Expecting 2 bytes for the abbreviation
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if(bytesReceived == SOCKET_ERROR){
        cerr<< "Recv failed: " << WSAGetLastError() << endl;
        closesocket(clientSocket);
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    //Print the abbreviation
    string abbreviation(buffer, 2);
    cout<< "Received abbreviation: " << abbreviation << endl;

    //Look for the state
    string response;
    auto st = stateMap.find(abbreviation);
    if(st != stateMap.end()){
        response = st->second;
    }else{
        response = "Invalid abbreviation";
    }

    // Send response (state name or error message)
    int bytesSent = send(clientSocket, response.c_str(), response.length() + 1, 0);
    if (bytesSent == SOCKET_ERROR) {
        cerr << "Send failed: " << WSAGetLastError() << endl;
    }

    //Closing the server
    closesocket(clientSocket);
    closesocket(serverSocket);

    //WSACleanup Winsock
    WSACleanup();


    return 0;
}
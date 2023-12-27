// // #include <iostream>
// // #include <winsock2.h>
// // #pragma comment(lib, "ws2_32.lib") 
// // using namespace std;

// // int main(){
// //     cout<<"Attempting to create a server"<<endl;

// //     SOCKET wssocket;
// //     SOCKET new_socket;
// //     WSADATA wsData;
// //     struct sockaddr_in server;
// //     int server_len ;
// //     int BUFFER_SIZE = 37020;

// //     if(WSAStartup(MAKEWORD(2,2), &wsData) != 0){
// //         cout<<"Could not initialize "<<endl;
// //     };

// //     // create a socket
// //     wssocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
// //     if(wssocket == INVALID_SOCKET){
// //         cout<<"Could not create socket "<<endl;
// //     }

// //     return 0;
// // }


// #include <iostream>
// #include <winsock2.h>

// #pragma comment(lib, "ws2_32.lib")  // Link with the Winsock library

// using namespace std;

// int main() {
//     cout << "Attempting to create a server" << endl;

//     SOCKET wssocket;
//     WSADATA wsData;
//     struct sockaddr_in server;
//     int server_len;
//     int BUFFER_SIZE = 37020;

//     if (WSAStartup(MAKEWORD(2, 2), &wsData) != 0) {
//         cout << "Could not initialize " << endl;
//         return 1;  // Exit the program if WSAStartup fails
//     }

//     // create a socket
//     wssocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//     if (wssocket == INVALID_SOCKET) {
//         cout << "Could not create socket " << endl;
//         WSACleanup();  // Cleanup Winsock resources before exiting
//         return 1;
//     }

//     return 0;
// }

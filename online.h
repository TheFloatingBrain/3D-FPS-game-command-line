#include <stdio.h>

double enx = 1.2 * 3;
double eny = 1.2 * 3;

#if defined(_WIN32) || defined(__CYGWIN__)
    WSADATA ws;
    SOCKET s;
    SOCKADDR_IN sa;
    SOCKET client_socket;
#else
    int s, client_socket;
    struct sockaddr_in sa;
#endif




void onlinesetup(void){
    #if defined(_WIN32) || defined(__CYGWIN__)
        WSAStartup(MAKEWORD(2,2), &ws);
    #endif
    s = socket(AF_INET, SOCK_STREAM, 0);
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(1234);
    #if defined(_WIN32) || defined(__CYGWIN__)
        WSACleanup();
    #endif
}

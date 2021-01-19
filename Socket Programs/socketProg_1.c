/**
 * @file socketProg_1.c
 * @author Braiden Gole
 * @brief This is my first socket program.
 *        Details:
 *              This is a simple socket program with a family address
 *              of AF_INET6 (dual-mode) socket compatibilty between (iPv4 & iPv6)
 *              addresses. Our connection type is defined under the macro [SOCK_STREAM]
 *              which is used to create a stable and reliable connection because it
 *              must be connected before any data can be sent or recieved. Also [SOCK_STREAM] is 
 *              a reliable two-way connection with OOB (Out of band) support.
 * @version 0.1
 * @date 2021-01-04
 * @copyright Copyright (c) Braiden Gole 2021
 * 
 * NOTE: Make sure to link the "winsock2" library.
 * NOTE: gcc -o test program.c -lws2_32 -Wall 
 * 
 *  [SOURCE Microsoft Sockets #include <winsock2.h>]: 
 *      https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-socket
 * 
 *  [SOURCE Microsoft Sockets #include <ws2tcpip.h>]
 *      https://docs.microsoft.com/en-us/windows/win32/api/ws2tcpip/
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int main(void)
{   
    // Windows scripting application structure definition.
    // Declare a variable for the typdef socket object.
    // Generate the versioning word expected by WSAStartup.
    WSADATA wsaData = { 0 };
    SOCKET dataSock = INVALID_SOCKET;
    WORD versioningWord = MAKEWORD(2, 2);

    const int KFAMILYADDRESS = AF_INET6;
    const int KTYPE = SOCK_STREAM;
    const int KPROTOCOL = IPPROTO_TCP;

    int callCode = 0;
    callCode = WSAStartup(versioningWord, &wsaData);
    if (callCode != 0)
    {
        fprintf(stderr, "Windows scripting application FAILED: %i", callCode);
        return 1;
    }

    // Initialize the socket calling the socket function.
    dataSock = socket(KFAMILYADDRESS, KTYPE, KPROTOCOL);
    if (dataSock == INVALID_SOCKET)
    {
        fprintf(stderr, "WSA [Error]: %i", WSAGetLastError());
        return 1;
    }

    // Shutdown check to ensure that no more outgoing or incomming data is
    // recieved before closing the socket we do not want to close the socket
    // abruptly.
    callCode = shutdown(dataSock, SD_BOTH);

    // Make sure that we close the socket and check the return value
    // for any errors that occured while closing the socket.
    callCode = closesocket(dataSock);
    if (callCode == SOCKET_ERROR)
    {
        fprintf(stderr, "WSA [Error]: %i", WSAGetLastError());

        // We made sure that we "shutdown" the above processes because
        // WSACleanup will cancel any threads that are still ongoing and
        // will not post any kind of message indicating that anything was done.
        WSACleanup();
        return 1;
    }
    WSACleanup();
    return 0;
}

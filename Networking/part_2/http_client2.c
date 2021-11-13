#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <string.h>

int main()
{

    int client_socket;
    struct sockaddr_in remote_address;
    char *request, response[2024];

    //Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    //ip address of www.msn.com (get by doing a ping www.msn.com at terminal)
    remote_address.sin_addr.s_addr = inet_addr("77.111.240.75");
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(80);

    //Connect to remote remote_address
    connect(client_socket, (struct sockaddr *)&remote_address, sizeof(remote_address));

    //Send some data
    request = "GET /?st=1 HTTP/1.1\r\nHost: www.eastwillsecurity.com\r\n\r\n";
    send(client_socket, request, strlen(request), 0);

    //Receive a reply from the remote_address
    recv(client_socket, response, sizeof(response), 0);
    printf("%s\n", response);

    close(client_socket);

    return 0;
}
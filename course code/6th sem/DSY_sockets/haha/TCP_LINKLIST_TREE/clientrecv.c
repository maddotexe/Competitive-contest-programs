#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in client;

    

    char buffer[256];
    char recbuffer[256];

    if (argc < 2) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[1]);
 while (1) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    

    bzero((char *) &client, sizeof(client));

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr("172.19.14.66");
    client.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &client,sizeof(client)) < 0) {
        error("ERROR connecting");
    }
 
    recbuffer[0] = '\0';

    n = read(sockfd,recbuffer,255);

    if (n < 0) {
         error("ERROR reading from socket");
    }

    printf("%s\n",recbuffer);

    close(sockfd);
 }
    return 0;
}

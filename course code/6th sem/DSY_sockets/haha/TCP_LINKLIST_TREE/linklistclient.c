#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

void delay (int m) {
	long pause;
	clock_t now, then;

	pause = m * (CLOCKS_PER_SEC/1000);
	now = then = clock();

	while ((now - then) < pause)
		now = clock();
}

struct nde {
	int data;
	struct nde * next;
};

typedef struct nde node;

int main(int argc, char *argv[])
{
	node *temp;
	node *head = (node *) malloc (sizeof(node));
	head->data = 1;
	temp = head;
	head->next = (node *) malloc (sizeof(node));
	head = head->next;
	head->data = 2;
	head->next = (node *) malloc (sizeof(node));
	head = head->next;
	head->data = 3;
	head->next = (node *) malloc (sizeof(node));
	head = head->next;
	head->data = 4;
	head->next = (node *) malloc (sizeof(node));
	head = head->next;
	head->data = 5;
	head->next = (node *) malloc (sizeof(node));
	head = head->next;
	head->data = 6;
	head->next = NULL;
    int sockfd, portno, n;

    struct sockaddr_in client;

    

    char buffer[256];
    

    if (argc < 2) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[1]);

// while (1) {
     sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    

    bzero((char *) &client, sizeof(client));

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr("192.168.92.131");
    client.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &client,sizeof(client)) < 0) {
        error("ERROR connecting");
    }
 printf("conencted to server\n");
//    gets(buffer);
	head = temp;

    n = write(sockfd,head,sizeof(node));

    if (n < 0) {
         error("ERROR writing to socket");
    }

    close(sockfd);
//printf("disconnected with server\n");
//delay (2000);	
//printf("disconnected with server\n");
node *add = head;

while (add != NULL) {
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    

    bzero((char *) &client, sizeof(client));

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr("192.168.92.131");
    client.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &client,sizeof(client)) < 0) {
        error("ERROR connecting");
    }
 
//    recbuffer[0] = '\0';

    n = read(sockfd,&add,sizeof(node *));
	

    if (n < 0) {
         error("ERROR reading from socket");
    }

	if (add == NULL)
		break;

    printf("%d\n",add->data);

    close(sockfd);
// 	3
sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &client, sizeof(client));

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr("192.168.92.131");
    client.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &client,sizeof(client)) < 0) {
        error("ERROR connecting");
    }
 printf("conencted to server\n");
//    gets(buffer);
	head = temp;

    n = write(sockfd,add,sizeof(node));

    if (n < 0) {
         error("ERROR writing to socket");
    }

    close(sockfd);
}
// }
    return 0;
}

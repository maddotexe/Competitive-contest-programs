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
	struct nde *left;
	struct nde *right;
};

typedef struct nde node;

void insert (node **head, int x) {
	if ((*head) == NULL) {
		(*head) = (node *) malloc (sizeof(node));
		(*head)->data = x;
		(*head)->left = NULL;
		(*head)->right = NULL;

		return;
	}

	if ((*head)->data > x) {
		insert (&((*head)->left), x);
	} else {
		insert (&((*head)->right), x);
	}

	return;
}

void inorder (node *head) {
	if (head == NULL) 
		return;

	inorder(head->left);
	printf("%d ", head->data);
	inorder(head->right);

	return;
}

int main(int argc, char *argv[]) {
	node *temp, *head = NULL;

	int num;
	int ii;
	scanf("%d", &num);
	for (ii = 0; ii < num; ii++) {
		int da;
		scanf("%d", &da);
		insert(&head, da);
		if (ii == 0)
			temp = head;

		head = temp;
	}

	head = temp;

	inorder(head);

//	scanf("%d", &num);

	
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
//	head = temp;

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

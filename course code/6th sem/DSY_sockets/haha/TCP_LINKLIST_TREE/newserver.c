/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

struct sockaddr_in serv_addr, cli_addr;
int sockfd, newsockfd, portno, k;
socklen_t clilen;

void error(const char *msg)
{
    perror(msg);
    exit(1);
}



struct nde {
	int data;
	struct nde *left;
	struct nde *right;
};

typedef struct nde node;

void inorder (node *head) {
	if (head == NULL) 
		return;

	inorder(head->left);
	printf("%d ", head->data);
	inorder(head->right);

	return;
}

void make (node **head) {
	if ((*head) == NULL)
		return;

	node **add = &((*head)->left);

	if ((*head)->left != NULL) {
     	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

     	if (newsockfd < 0) {
		error("ERROR on accept");
     	}
 
     	int n = write(newsockfd,add,sizeof(node *));

     	if (n < 0) {
	     error("ERROR writing to socket");
     	}
     
 	close(newsockfd);

	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

     	if (newsockfd < 0) {
		error("ERROR on accept");
     	}

	node *temp = (node *) malloc (sizeof(node));
	temp->data = -1;
	temp->left = NULL;
	temp->right = NULL;
	n = read(newsockfd, temp, sizeof(node));

     	if (n < 0) {
	     error("ERROR reading from socket");
     	}

	if (temp == NULL)
		(*head)->left = NULL;
	else {
     		printf("Here is the message: %d\n",temp->data);
		(*head)->left = temp;
	}

	close(newsockfd);
	make (&((*head)->left));
	}

// RIGHT
	add = &((*head)->right);

	if ((*head)->right != NULL) {
     	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

     	if (newsockfd < 0) {
		error("ERROR on accept");
     	}
 //    buffer[0] = modbuffer;
     	int n = write(newsockfd,add,sizeof(node *));

     	if (n < 0) {
	     error("ERROR writing to socket");
     	}
     
 	close(newsockfd);

	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

     	if (newsockfd < 0) {
		error("ERROR on accept");
     	}

	node *temp = (node *) malloc (sizeof(node));
	temp->data = -1;
	temp->left = NULL;
	temp->right = NULL;
	n = read(newsockfd, temp, sizeof(node));

     	if (n < 0) {
	     error("ERROR reading from socket");
     	}

	if (temp == NULL)
		(*head)->right = NULL;
	else {
     		printf("Here is the message: %d\n",temp->data);
		(*head)->right= temp;
	}

	close(newsockfd);
	make (&((*head)->right));
	}
	
	return;
}


int main(int argc, char *argv[])
{
	node *head = (node *) malloc (sizeof(node));
	head->data = -1;
	head->right = NULL;
	head->left = NULL;
     

     char buffer[256];
     char modbuffer;

     

     int n;

     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }

     sockfd = socket(AF_INET, SOCK_STREAM, 0);

     if (sockfd < 0) {
        error("ERROR opening socket");
     }

     bzero((char *) &serv_addr, sizeof(serv_addr));

     portno = atoi(argv[1]);

     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);

     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
              error("ERROR on binding");
     }

     listen(sockfd,5);

     clilen = sizeof(cli_addr);
// while (1) {
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

     if (newsockfd < 0) {
		error("ERROR on accept");
     }

     for (k = 0; k < 255; k++) {
	     buffer[k] = '\0';
     }

     n = read(newsockfd, head, sizeof(node));

     if (n < 0) {
	     error("ERROR reading from socket");
     }
     printf("Here is the message: %d\n",head->data);
 //    modbuffer = buffer[0] - 1;
   //  printf("Here is the modified message: %c\n",modbuffer);
     close(newsockfd);
//printf("disconnected with client\n");	
	make (&head);
	close(sockfd);
	inorder(head);
     

     return 0; 
}

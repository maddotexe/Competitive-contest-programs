/*
   C socket server example, handles multiple clients using threads
   Compile
   gcc server.c -lpthread -o server
 */
#include<stdio.h>
#include<string.h> //strlen
#include<stdlib.h> //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h> //write
#include<pthread.h> //for threading , link with lpthread
//the thread function
void *connection_handler(void *);
int lamport_clock = 0;
pthread_t thread_recv;
pthread_t thread_send;

int main(int argc , char *argv[])
{
	int socket_desc , client_sock , c;
	struct sockaddr_in server , client;
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons( 5000 );
	//Bind
	puts("bind done");
	//Listen
	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	if ( (client_sock = connect(socket_desc, (struct sockaddr *)&client, sizeof((struct sockaddr *)&client))) )
	{
		puts("Connection accepted");
		if( pthread_create( &thread_recv , NULL , connection_handler , (void*) &socket_desc) < 0)
		{
			perror("could not create thread");
			return 1;
		} else {
			puts("yes else");
		//	printf("%s\n", (char *)thread_id);
		}
		//Now join the thread , so that we dont terminate before the thread
		pthread_join( thread_recv , NULL);
		puts("Handler assigned");
	}
	if (client_sock < 0)
	{
		perror("accept failed");
		return 1;
	}
	return 0;
}
/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
	puts("here am i ");
//	while (true) {
		//Get the socket descriptor
		int sock = *(int*)socket_desc;
		int n;
		char message[1000];
		while (n = read(sock, message, 1000)) {
			if (n == -1) {
				break;
			}
			puts("message recv");
		}
	
	return 0;
} 

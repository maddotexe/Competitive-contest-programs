# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <string.h>
# include <stdlib.h>

# define MAXBUF 1024

int main()
{
	char buff[MAXBUF];
	int l;
	int fd1 = 0,fd2 = 0, rs = 0, addrlen = 0;
	struct sockaddr_in server_addr, client1_addr, client2_addr;
	int PORT1 = 4000, PORT2 = 3000;
	// creating socket
	fd1 = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd1 == -1) {
		printf("could not create a socket\n");
		exit(1);
	} else {
		printf("Socket Created\n");
	}
	//memset(&client_addr, 0, sizeof(client_addr));
	//memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(6000);
	
	client1_addr.sin_family = AF_INET;
	client1_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	client1_addr.sin_port = htons(PORT1);

	rs = bind(fd1, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (rs == -1) {
		printf("Could not bind to address\n");
		close(fd1);
		exit(1);
	} else {
		printf("Bind Completed\n");
	}

	printf("waiting........\n");
	while(1) {
		addrlen = sizeof(client1_addr);
		rs = recvfrom(fd1, buff, 100, 0, (struct sockaddr *)&client1_addr, &addrlen);
		if (rs == -1) {
			printf("Could not recieve message\n");
		} else {
			printf("Recieved : %s\n", buff);
			l = sizeof(buff);
			printf("d\n", l);
			close(fd1);
			
			fd2 = socket(AF_INET,SOCK_DGRAM,0);
			if (fd2 == -1) {
				printf("Could not create a socket\n");
			} else {
				printf("Socket Created\n");
			}

			client2_addr.sin_family = AF_INET;
			client2_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
			client2_addr.sin_port = htons(PORT2);
		
			rs = bind(fd2, (struct sockaddr *)&server_addr, sizeof(server_addr));
			if (rs == -1) {
				printf("Could not bind to address\n");
				close(fd1);
				exit(1);
			} else {
				printf("Bind Completed\n");
			}
				rs = sendto(fd2, buff, strlen(buff) + 1, 0, (struct sockaddr *)&client2_addr, sizeof(client2_addr));
				if (rs == -1) {
					printf("Could not send message\n");
				} else {
					printf("Message Send\n");
				}

		}
	}
	close(fd1);
	close(fd2);
	return 0;
}

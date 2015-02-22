# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <string.h>
# include <stdlib.h>

# define MAXBUF 1024

int main()
{
	int buff = 10;
	int l = 0;
	int fd, fd1 = 0,fd2 = 0, rs = 0, addrlen = 0;
	struct sockaddr_in server_addr, client1_addr, client2_addr;
	int PORT1 = 4000, PORT2 = 3000;
	// creating socket
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd == -1) {
		printf("could not create a socket\n");
		exit(1);
	} 
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(6000);
	
	client1_addr.sin_family = AF_INET;
	client1_addr.sin_addr.s_addr = INADDR_ANY;
	client1_addr.sin_port = htons(PORT1);
	
	client2_addr.sin_family = AF_INET;
	client2_addr.sin_addr.s_addr = INADDR_ANY;
	client2_addr.sin_port = htons(PORT2);

	rs = bind(fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if (rs == -1) {
		printf("Could not bind to adhgdgdress\n");
		close(fd1);
		exit(1);
	}
	
	while(1) {
		addrlen = sizeof(client1_addr);
		rs = recvfrom(fd, buff, sizeof(buff), 0, (struct sockaddr *)&client1_addr, &addrlen);
		if (rs == -1) {
			printf("Could not recieve message\n");
		} else {
			rs = sendto(fd, buff, sizeof(int), 0, (struct sockaddr *)&client2_addr, sizeof(client2_addr));
			if (rs == -1) {
				printf("Could not send message\n");
			} else {
				printf("Message Send\n");
				close(fd);
				break;
			}
			} else {
				printf("Could not found\n");	
			}		
		}
	}
	
	return 0;
}

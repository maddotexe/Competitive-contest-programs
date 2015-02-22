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
	int fd = 0, rs = 0, addrlen = 0;
	struct sockaddr_in server_addr, client_addr;
	// creating socket
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd == -1) {
		printf("could not create a socket\n");
		exit(1);
	} else {
		printf("Socket Created\n");
	}
	memset(&client_addr, 0, sizeof(client_addr));
	memset(&server_addr, 0, sizeof(server_addr));

	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = INADDR_ANY;
	client_addr.sin_port = htons(3000);
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	//inet_pton(AF_INET, "172.20.33.111", &server_addr);
	server_addr.sin_port = htons(6000);

	rs = bind(fd, (struct sockaddr *)&client_addr, sizeof(client_addr));
	if (rs == -1) {
		printf("Could not bind to address\n");
		close(fd);
		exit(1);
	} else {
		printf("Bind Completed\n");
	}
	while(1){
	addrlen = sizeof(server_addr);
	rs = recvfrom(fd, buff, 100, 0, (struct sockaddr *)&server_addr, &addrlen);
	if (rs == -1) {
		printf("Could not recieve message\n");
	} else {
			printf("Message Recievd : %s\n", buff);
	}
	
	}
	close(fd);
	return 0;
}

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>

int main()
{
	int fd, temp, newfd;
	struct sockaddr_in serv_addr;
	char *a = "172.20.33.118";
	char *msg ="hello";
	
	fd = socket ( AF_INET, SOCK_STREAM, 0);
	if ( fd == -1 ) {
		printf("fd is -1");
		exit ( fd);
	}

	bzero ( &serv_addr, sizeof(serv_addr) );

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(3001);
	inet_pton ( AF_INET , a, &serv_addr.sin_addr );

	temp = bind ( fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr) );
	if ( temp == -1 )
	{
		printf("bind is -1");
		exit(fd);
	}
	
	serv_addr.sin_port = htons(3000);
	temp = connect ( fd, ( struct sockaddr *)&serv_addr, sizeof(serv_addr) );
	if ( temp == 0)
		printf("Connection is successful\n");

	
	send(fd,(const char*)msg,6,0);

	close(fd);
	return 0;
}

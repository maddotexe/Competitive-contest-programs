#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>

int main()
{
        int fd, temp, temp2, newfd;
        struct sockaddr_in myaddr, cliaddr;
        char *addr = "172.20.33.118";
	char msg[10];

        fd = socket ( AF_INET, SOCK_STREAM, 0);
        if ( fd == -1 ) {
                printf("fd is -1");
                return 0;
        }
	printf ( "fd = %d \n" , fd);
	
        bzero ( &myaddr, sizeof(myaddr) );
	bzero ( &cliaddr, sizeof(cliaddr) );

        myaddr.sin_family = AF_INET;
        myaddr.sin_port = htons(3000);
        inet_pton ( AF_INET , addr, &myaddr.sin_addr );

        temp = bind ( fd, (struct sockaddr *)&myaddr, sizeof(myaddr) );
        if ( temp == -1 )
        {
                printf("bind is -1");
                return 0;
        }
	printf ( "temp = %d\n" , temp);
	
	temp2 = listen ( fd, 5 );
	if ( temp2 == -1 ) {
		return 0;
	}
	printf ( "temp2 = %d\n" , temp2);
	int addrlen ;
	newfd = accept(fd, (struct sockaddr *)&cliaddr, &addrlen);
	if ( newfd > 0) {
		printf("Connection is successful\n");
	}

	recv(fd,(char*)msg,6,0);
	printf("%s",msg);
	
	close(fd);
        close(newfd);

	return 0;

}

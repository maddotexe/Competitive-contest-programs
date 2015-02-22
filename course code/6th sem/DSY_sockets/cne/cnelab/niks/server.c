#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int fd,temp,k,new_fd,new_fd1;
	char *buf;
	struct sockaddr_in myaddr,client1,client2;
	socklen_t fromlen;
	char ch;

	buf = &ch;
	memset(&myaddr, 0, sizeof(myaddr));
	fd = socket(AF_INET,SOCK_STREAM,0);
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(8888);
	myaddr.sin_addr.s_addr = INADDR_ANY;

	temp = bind(fd,(struct sockaddr *)&myaddr,sizeof(myaddr));
	if(temp == -1) {
		printf("can't bind\n");
		close(fd);
		exit(1);
	}

	temp = listen(fd,5);
	if(temp == -1) {
		printf("Can't listen\n");
		close(fd);
		exit(1);
	}
	memset(&client1, 0, sizeof(client1));

	fromlen = sizeof(client1);
	new_fd = accept(fd,(struct sockaddr *)&client1,&fromlen);

	if(new_fd == -1) { 
		printf("Can't accept connections");
		close(fd);
		exit(1);
	}

	k = recv(new_fd,buf,sizeof(buf),0);

	printf("The received character is %c\n",*buf);
	
	   
        memset(&client2, 0, sizeof(client2));

        fromlen = sizeof(client2);
        new_fd1 = accept(fd,(struct sockaddr *)&client2,&fromlen);

        if(new_fd1 == -1) {
                printf("Can't accept connections from 2nd client");
                close(fd);
                exit(1);
        }
	*buf = (*buf) - 1;
        k = send(new_fd1,buf,sizeof(buf),0);

	close(fd);
	close(new_fd);
	close(new_fd1);
	return 0;
}
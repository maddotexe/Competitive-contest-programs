#include <sys/socket.h>  
#include <netinet/in.h>  
#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>  
#include <arpa/inet.h>  
#include <unistd.h> 

int main()
{
	FILE *fp;

	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd == -1) {
          printf("cannot create socket !!\n");
          return 0;
    	}
    
    	struct sockaddr_in server, client;
    	bzero(&server, sizeof(server));
    	bzero(&client, sizeof(client));
    
    	server.sin_family = AF_INET;
    	server.sin_port = htons(7780);
    	server.sin_addr.s_addr = INADDR_ANY;
    
    	if(bind(fd, (struct sockaddr*)&server, sizeof(server)) != 0)  {
                printf("cannot bind socket !!\n");
                close(fd);
                return 0;
    	}
    
   	int addr_len, len;
    	char msg[100];
    
    	while(1)  {
		char b1;
		char ch1 = '\n';
		int flag = 0;
		int k;
		
		for (k = 0; k < 100; k++) {
			msg[k] = '\0';
		}

       		addr_len = sizeof(client);
       		len = recvfrom(fd, msg, 100, 0, (struct sockaddr*)&client, &addr_len);       
       		printf("%s\n", msg);
		char c1 = msg[0];
		printf("read character\n");
		fp = fopen("test.txt","r");
		printf("opened file\n");
		int i = 0;
		while (ch1 != EOF) {
			printf("in loop\n");
			b1 = ch1;
			printf("in loop\n");
			ch1 = fgetc(fp);
			printf("read character\n");
			if((ch1 == c1) && (b1 == '\n')) {
				flag = 1;
				ch1 = fgetc(fp);
				ch1 = fgetc(fp);
				while (ch1 != '\n') {
					msg[i] = ch1;
					ch1 = fgetc(fp);
					i++;
				}
				break;
			}
		}
		fclose(fp);
		printf("file closed\n");
		msg[i] = '\0';
		if (flag == 0) {
			strcpy(msg, "not found");
		}
		printf("here is the modified msg : %s", msg);
        	len = sendto(fd, msg, strlen(msg), 0, (struct sockaddr*)&client, sizeof(client));

    	}
    	close (fd);
    	return 0;
    
}
            

#include <sys/socket.h>  
#include <netinet/in.h>  
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h> 
#include <arpa/inet.h> 
//#include <fcntl.h> 
#include <unistd.h> 
#include <time.h>

main() 
{
	int i = 0;

while(1) {

    char temp = '\0';
    if (temp = getchar()) {
    int sock_desc = socket(AF_INET, SOCK_STREAM, 0); 
    if (sock_desc == -1)
    {
        printf("cannot create socket!\n");
        return 0;
    }

    struct sockaddr_in client;  
    memset(&client, 0, sizeof(client));  
    client.sin_family = AF_INET;  
    client.sin_addr.s_addr = inet_addr("172.20.33.19");  
    client.sin_port = htons(1234);  


    if (connect(sock_desc, (struct sockaddr*)&client, sizeof(client)) != 0)
    {
        printf("cannot connect to server!\n");
        close(sock_desc);
    }

    char buf[100];
    char c = '\n';
    char *p_buf;
    int k, len;  

    while(1) 
    {      
        gets(buf);

        len = strlen(buf);
        p_buf = buf;

        while (len > 0)
        {
            k = send(sock_desc, p_buf, len, 0);      
            if (k == -1)
            {
                printf("cannot write to server!\n");
                break;
            }

           // p_buf += k;
           // len -= k;
	    break;
        }

        k = send(sock_desc, &c, 1, 0);      
        if (k == -1)
        {
            printf("cannot write to server!\n");
            break;
        }

        if (strcmp(buf, "exit") == 0)          
            break;  
    }  
      

    close(sock_desc);
    }
}

    return 0;  
} 

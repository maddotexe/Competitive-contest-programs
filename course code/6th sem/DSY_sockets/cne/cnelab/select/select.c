#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define PORT "9034"

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
int confirm(char usr[], char pass[]){
    FILE *fp;
    int ctr = 0;
    char u[20], p[20];
    fprintf(stdout,"usr : %s pass : %s \n", usr, pass);

    fp = fopen("database", "r");
    if(!fp){
        printf("file error");
        exit(0);
    }
    while(!feof(fp)){
        ctr++;
        fscanf(fp,"%s %s", u, p);
//        fprintf(stdout,"%s %s \n", u, p);

        if(strcmp(u, usr) == 0 && strcmp(p, pass) == 0){
            printf("\n %d Aunthenticated", ctr);
          return 1;  
        } 
    }
    printf("\n Not Aunthenticated", ctr);

    return 0;
}
int main(void)
{
    char usr[20], pass[20];
    int conf, l1;
    fd_set master;    
    fd_set read_fds;  
    int fdmax;    
    int listener; 
    int newfd;        
    struct sockaddr_storage remoteaddr;
    socklen_t addrlen;
    char buf[256];    
    int nbytes;
    char remoteIP[INET6_ADDRSTRLEN];
    int yes=1;        
    int i, j, rv;
    struct addrinfo hints, *ai, *p;
    FD_ZERO(&master);   
    FD_ZERO(&read_fds);
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if ((rv = getaddrinfo(NULL, PORT, &hints, &ai)) != 0) {
        fprintf(stderr, "selectserver: %s\n", gai_strerror(rv));
        exit(1);
    }
    for(p = ai; p != NULL; p = p->ai_next) {
        listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (listener < 0) { 
            continue;
        }   
        setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
        if (bind(listener, p->ai_addr, p->ai_addrlen) < 0) {
            close(listener);
            continue;
        }
        break;
    }
    if (p == NULL) {
        fprintf(stderr, "selectserver: failed to bind\n");
        exit(2);
    }
    freeaddrinfo(ai);
    if (listen(listener, 10) == -1) {
        perror("listen");
        exit(3);
    }
    FD_SET(listener, &master);
    fdmax = listener; 

    for(;;) {
        read_fds = master;
        if (select(fdmax+1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(4);
        }
        for(i = 0; i <= fdmax; i++) {

            if (FD_ISSET(i, &read_fds)) { // we got one!!
                if (i == listener) {
                    // handle new connections
                    addrlen = sizeof remoteaddr;
                    newfd = accept(listener,
                        (struct sockaddr *)&remoteaddr,
                        &addrlen);

                    send(j, "Send authentication", strlen("Send authentication")+1, 0);
                    nbytes = recv(newfd, usr, sizeof(usr), 0);
                    nbytes = recv(newfd, usr, sizeof(usr), 0);
                    nbytes = recv(newfd, pass, sizeof(pass), 0);
                  //  nbytes = recv(newfd, pass, sizeof(pass), 0);
                    l1 = strlen(usr);
                    usr[l1-1] = '\0';
                    l1 = strlen(pass);
                    pass[l1-1] = '\0';
                    conf = 0;
  //                  fprintf(stdout,"sr = %s pas = %s \n", usr, pass);
//                    getchar();
                    if (newfd == -1) {
                        perror("accept");

                    }
                     else {
                        conf = 1;
                        conf = confirm(usr,pass);
                        if(conf == 1){

                        FD_SET(newfd, &master); 
                        if (newfd > fdmax) {    
                            fdmax = newfd;
                        }
                        printf("selectserver: new connection from %s on "
                            "socket %d\n",
                            inet_ntop(remoteaddr.ss_family,
                                get_in_addr((struct sockaddr*)&remoteaddr),
                                remoteIP, INET6_ADDRSTRLEN),
                            newfd);
                        }
                    }
                    
                } else {

                    if ((nbytes = recv(i, buf, sizeof buf, 0)) <= 0) {
                        if (nbytes == 0) {
                            printf("selectserver: socket %d hung up\n", i);
                        } else {
                            perror("recv");
                        }
                        close(i); 
                        FD_CLR(i, &master);
                    } else {
                        for(j = 0; j <= fdmax; j++) {
                            if (FD_ISSET(j, &master)) {
                                if (j != listener && j != i) {
                                    if (send(j, buf, nbytes, 0) == -1) {
                                        perror("send");
                                    }
                                }
                            }
                        }
                    }
                } 
            }
        } 
    } 
    return 0;
}
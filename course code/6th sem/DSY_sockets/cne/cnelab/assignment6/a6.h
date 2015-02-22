int recvtimeout(int s, char *buf, int len, int timeout)
{
    fd_set fds;
    int n;
    struct timeval tv;

    // set up the file descriptor set
    FD_ZERO(&fds);
    FD_SET(s, &fds);

    // set up the struct timeval for the timeout
    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    // wait until timeout or data received
    n = select(s+1, &fds, NULL, NULL, &tv);
    if (n == 0) return -2; // timeout!
    if (n == -1) return -1; // error

    // data must be here, so do a normal recv()
    return recv(s, buf, len, 0);
}

void chk(char str[], char check[]){
   int sum=0,i =0;
   while(str[i]!='\0') {
        int n = str[i];
        sum += n;
        i++;
    }
    int j = 0;
    int t = 4;
    while(t--){
        check[j++] = sum%10+48;
        sum /= 10;
    }
    check[j] = '\0';
}
int decode(char str[], char msg[]){
    int l = strlen(str);
    char check[10];
    int i, j=0,k=0;
    for( i = 1; i < l-5; i++){
        if(!(str[i] == '?' && str[i+1] == '?'))
        msg[j++] = str[i];
    
}    msg[j] = '\0';
 //   cout << msg << endl;
    for(; i < l-1; i++){
        check[k++] = str[i];
    }
    check[k] = '\0';
    char c[5];
    chk(msg, c);
    int flag = 0, p;
    for(p=0;p<4;p++){
        if(c[p] != check[p]){
            flag = 1;
            break;
        }
    }
 //   cout << check << " : " << c << endl;
    if(flag) return 0;
    else return 1; 
}
void readfile(int newsd){
    FILE *fp;
    int M = 40;     // bytes limited per frame
    int ctr = 0, t, n, f, l;
    char u[100];
    fp = fopen("input", "r");
    if(!fp){
        printf("file error");
        exit(0);
    }
    fscanf(fp,"%d", &n);
    t = n;
    int ct = 0;
    char str[100];
    int val=0;
    printf("Total Packets = %d\n", n);    
    while(t--){
        ctr++;
        printf("Packet no-  %d ", ctr);
        char frame[M];
        fscanf(fp,"%d %s", &f, u);
        int size = strlen(u);
        int i=0,j=0;
        ct=0;
        while(j <= size){
            ct++;
        i=0;
        val = 0;
        frame[i++] = '?';
        while(1){
            if(u[j] == '?'){
                frame[i++] = '?';
            }           
            char ch = u[j++];
            frame[i++] = ch;;
            str[val++] = ch;
            if(i >= M || j == size) break;
        }
        str[val]='\0';
        char check[5];
        chk(str,check);
        frame[i++] = check[0];
        frame[i++] = check[1];
        frame[i++] = check[2];
        frame[i++] = check[3];
        frame[i++] = '?';
        frame[i++] = '\0';
        char buf[100];
        if(strlen(frame) > 2)
            send(newsd, frame, strlen(frame)+1, 0);
            int b = recvtimeout(newsd, buf, 10, 5);
            if(b == -1){
                printf("rcv error");
                send(newsd, frame, strlen(frame)+1, 0);
            }
            else if(b == -2){
                printf("timeout\n");
                send(newsd, frame, strlen(frame)+1, 0);
            }
            else{
                printf("successfully sent\n");
            }
        }
    }
}

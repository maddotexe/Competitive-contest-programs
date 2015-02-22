#define _CRT_SECURE_NO_WARNINGS 1
#define _NO_ARGS 0
#include <stdio.h>

FILE *fin, *fout;

void print(char *str, int tab);
int unknown(char ch);

int main(int argc, char **argv) {
    char ch, pr, temp[1024];
    int tab = 0, cnt, carr;
    if(_NO_ARGS) {
        scanf("%s", temp);
        fin = fopen(temp, "rb");
        scanf("%s", temp);
        fout = fopen(temp, "wb");
    }
    else if(argc < 2) {
        printf("insufficient arguments...\n");
        return 1;
    }
    else if(argc < 3) {
        fin = fopen(argv[1], "rb");
        fout = fopen("noname.c", "wb");
    }
    else {
        fin = fopen(argv[1], "rb");
        fout = fopen(argv[2], "wb");
    }
    if(!fin || !fout) {
        printf("file error...\n");
        return 2;
    }
    print("#include <stdio.h>", tab);
    print("", tab);
    print("char buff[1024];", tab);
    print("", tab);
    print("int main() {", tab++);
    print("char *p = buff;", tab);
    pr = 0;
    cnt = 0;
    carr = 0;
    while((ch=fgetc(fin))!=EOF) {
        if(unknown(ch)) continue;
        if(ch=='.' || ch==',' || ch=='[' || ch==']') {
            if(carr) {
                if(pr=='+') sprintf(temp, "(*p) += %d;", cnt);
                else if(pr=='-') sprintf(temp, "(*p) -= %d;", cnt);
                else if(pr=='>') sprintf(temp, "p += %d;", cnt);
                else if(pr=='<') sprintf(temp, "p -= %d;", cnt);
                carr = cnt = 0;
                print(temp, tab);
            }
            if(ch=='.') print("putchar(*p);", tab);
            else if(ch==',') print("*p = getchar();", tab);
            else if(ch=='[') print("while(*p) {", tab++);
            else if(ch==']') print("}", --tab);
        }
        else if(ch==pr || !carr) {
            carr = 1;
            cnt++;
        }
        else {
            if(pr=='+') sprintf(temp, "(*p) += %d;", cnt);
            else if(pr=='-') sprintf(temp, "(*p) -= %d;", cnt);
            else if(pr=='>') sprintf(temp, "p += %d;", cnt);
            else if(pr=='<') sprintf(temp, "p -= %d;", cnt);
            carr = cnt = 1;
            print(temp, tab);
        }
        pr = ch;
    }
    if(carr) {
        if(pr=='+') sprintf(temp, "(*p) += %d;", cnt);
        else if(pr=='-') sprintf(temp, "(*p) -= %d;", cnt);
        else if(pr=='>') sprintf(temp, "p += %d;", cnt);
        else if(pr=='<') sprintf(temp, "p -= %d;", cnt);
        print(temp, tab);
    }
    print("return 0;", tab);
    print("}", --tab);
    fclose(fin);
    fclose(fout);
    return 0;
}

void print(char *str, int tab) {
    int i;
    if(str[0]) {
        for(i=0; i<tab; i++) fputc('\t', fout);
        for(i=0; str[i]; i++) fputc(str[i], fout);
    }
    fputc('\n', fout);
}

int unknown(char ch) {
    switch(ch) {
        case '+':
        case '-':
        case '<':
        case '>':
        case '.':
        case ',':
        case '[':
        case ']': return 0;
        default : return 1;
    }
    return 1;
}

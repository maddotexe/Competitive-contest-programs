#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
int main()
{
    	int n;
        char s[1100];
        
        while (1) {
        	if (scanf("%s", s) == EOF ) break;
                int i = 0;
                while (s[i] >= s[i + 1] && i < strlen(s) - 1) {
                        i++;
                }
                for (int j = 0; j < strlen(s); j++) {
                        if(j != i) printf("%c", s[j]);
                }
                
                printf("\n");
        }
        
        return 0;
}

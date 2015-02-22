#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
 
using namespace std;
#define max 100007

int a[max] = {0};
int y = 0;

void sieve(){
        for(int i = 2; i <= max; i++){
                if (a[i] != 0)
			continue;
		a[i] = i;
                for(int j = 2 * i; j <= max; j += i) {
                        if (a[j] == 0)
                        a[j] = i;
                }        
        }        
}
 
int main()
{
    sieve();
    int c, n;
    for (int i = 2; i <= 100000; i++) {
    	printf("%d:", i);
    	n = i;
    	if (a[n] != 0) {
    		c = 0;
    		while (n % a[n] == 0) {
    			if (a[n] != c) {
    				printf(" %d", a[n]);
    				c = a[n];
    			}
    			if (a[n] == 0) break;
    			n /= a[n];
    			if(a[n] == 0) break;
    		}
    	} else {
    		printf(" %d", i);
    	}
    	printf("\n");
    }
    return 0;
}

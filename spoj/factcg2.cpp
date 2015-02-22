#include <iostream>
#include <cstdio>

#define max 10000007

using namespace std;

int a[max]={0};

void sieve(){
        for(int i = 2; i <= max; i++){
                if (a[i] != 0)
			continue;
                for(int j = 2 * i; j <= max; j += i) {
                        if (a[j] == 0)
                        a[j] = i;
                }        
        }        
}

int main()
{
	int n;
	sieve();
	
	while (scanf("%d", &n) != EOF) {
		if (n == 1) {
			printf("%d\n", n);
			continue;
		} else {
			printf("1");
		}
		
		if (a[n] != 0) {
			while (n % a[n] == 0) {
				printf(" x %d" , a[n]);
				if (a[n] == 0) break;
				n /= a[n];
				if (a[n] == 0) break;
			}
		}
		printf(" x %d\n", n);
	}
	
	return 0;
}

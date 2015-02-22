#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	char a[110];
	
	while(scanf("%s", a) == 1) {
		if (strlen(a) == 1 && a[0] == '1') {
			printf("1\n");
		}
		int d = 0;
		for (int i = strlen(a) - 1; i >= 0; i--) {
			int c = a[i] - 48;
			c *= 2;
			int g = c % 10;
			a[i] = g + 48 + d;
			d = c / 10;
		}
		if (d) {
			printf("%d", d);
		}
		for (int i = 0; i < strlen(a); i++) {
			printf("%c", a[i]);
		}
		puts("");
	}
	
	return 0;
}
		
			
		
	

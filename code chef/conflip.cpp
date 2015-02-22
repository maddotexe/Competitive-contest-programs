#include <stdio.h>

int main()
{
	
	int t;
	int i;
	int n;
	int q;
	int g;
	
	scanf("%d", &t);
	while (t--){
		scanf("%d", &g);
		while (g--){
			scanf("%d%d%d", &i, &n, &q);
		
			if (n % 2 == 0) {
				printf("%d\n", n / 2);
			} else {
				if (i == 1) {
					if (q == 1) {
						printf("%d\n", n / 2);
					} else {
						printf("%d\n", n / 2 + 1);
					}
				} else {
					if (q == 2) {
						printf("%d\n", n / 2);
					} else {
						printf("%d\n", n / 2 + 1);
					}
				}
			}
		}
	}
	return 0;
}
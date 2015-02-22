#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	int a[3];
	
	int t, j, k;
	unsigned long long int sum;
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d%d%d%d", &n, &a[0], &a[1], &a[2]);
		
		sort(a, a + 3);
		sum = 0;
		
		for (int i = 0; i <= a[0]; i++) {
			j = 0;
			while (j <= a[1]) {
				k = i + j;
				k = n - k;
				if (i + j > n) {
					break;
				}
				if (k < a[2]) {
					sum += k + 1;
				} else {
					sum += a[2] + 1;
				}
				
				j++;
				
			}
		}
				
		printf("%lld\n", sum);
	}
	
	return 0;
}
		

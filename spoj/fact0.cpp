#include <iostream>
#include <cstdio>

using namespace std;

#define ull unsigned long long

int main()
{
	ull n;
	
	while ((scanf("%llu", &n) == 1) && n) {
		ull i = 2;
		
		while (i * i <= n) {
			int t = 0;
			int g = 0;
			if (n % i == 0) {
				g = i;
				while (n % i == 0) {
					t++;
					n /= i;
				}
				printf("%llu^%d ", i, t);
			}
			
			if (n == 1) break;
			
			i++;
		}
		
		if (n > 1) printf("%llu^1", n);
		puts("");
	}
	
	return 0;
}

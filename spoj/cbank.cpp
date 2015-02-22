#include <iostream>
#include <cstdio>

using namespace std;

#define m 1000000007

int main()
{
	long long int n, t;
	
	cin >> t;
	
	while(t--) {
		scanf("%lld", &n);
		
		long long int f = (n * n) % m;
		
		long long int g = f;
		
		f = (f * n) % m;
		g = (g * 6) % m;
		
		long long int y = (11 * n) % m;
		
		f = (f + g + y + 6) % m;
		f = (f * 166666668) % m;
		
		printf("%lld\n", f);
	}
	
	return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long int d, f, b, m, t, x;
	
	
	while (1) {
		scanf("%lld%lld%lld%lld", &d, &f, &b, &m);
		if (d == 0 && f == 0 && b == 0 && m == 0) return 0;
		
		x = ((f * (f + 1) / 2) + 1) * b;
		
		x = d - x;
		
		if (x > m) {
			printf("Farmer Cream will have %lld Bsf to spend.\n", x);
		} else {
			printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n", m - x);
		}
		
	}
	
	return 0;
}

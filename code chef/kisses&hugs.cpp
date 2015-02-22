#include <stdio.h>

unsigned long long int power(int s)
{
	if (s == 0) return 1;
	else if (s == 1) return 2;
	else {
		unsigned long long int d = power(s/2);
		d = (d*d) %1000000007;
		if (s & 1) {
			d <<= 1;
			d %= 1000000007;
		}
		return d;
	}
}

int main()
{
	int t;
	unsigned long long int n,x,d;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		x = power((n+1)/2);
		d = x;
		d--;
		d <<= 1;
		if(d > 1000000007)
			d -= 1000000007;
		if(n%2==0){
			d += x;
			if(d > 1000000007)
				d -= 1000000007;
		}
		printf("%lld\n", d);
	}
	return 0;
}

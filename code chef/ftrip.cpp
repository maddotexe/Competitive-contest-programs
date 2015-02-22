#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

double C(long long n, long long r)
{
	if (r==0) 
		return 1;
	else 
		return C(n-1,r-1) * n / r;
}
int main()
{
	double ans1,ans2,ans3;
	double c;
	long long s,n,m,k,t,i;
	scanf("%lld", &t);	
	while (t--) {
		scanf("%lld%lld%lld%lld", &s, &n, &m, &k);
		s--;
		n--;
		m--;
		ans2 = (double)(C(s, min(n, s-n)));
		c = 0;
		for (i = k; i <= m; i++) {
			if (m >= i && s-m >= n-i) { 
				if (i >= 0 && n-i >= 0) 
					c += C(m, min(i,m-i))*C(s-m, min(n-i,s-m-n+i));
			}
		}
		ans1 = (double)(c);
		ans3 = (double)(ans1)/(double)(ans2);
		printf("%0.6f\n", ans3);
	}
	return 0;
}

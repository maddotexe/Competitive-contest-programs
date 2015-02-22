#include <iostream>
#include <cstdio>

using namespace std;

long long int hc(long long int a, long long int b) {
	if (b % a == 0) {
		return a;
	}
	return hc(b % a, a);
}
/*
inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}
*/
int main()
{
	int t;
	long long int x, y, z;
	
	cin >> t;
	
	while (t--) {
		/*fastRead(&x);
		fastRead(&y);
		fastRead(&z);*/
		
		scanf("%lld%lld%lld", &x, &y, &z);
		
		if (x < z && y < z) {
			printf("NO\n");
			continue;
		}
		if (x > y) {
			x = hc(y, x);
		} else {
			x = hc(x, y);
		}
		
		if (z % x == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		
	}
	
	return 0;
}
		
		
		

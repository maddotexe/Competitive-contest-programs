#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define ll long long

inline void fastRead(ll *a)
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


int main() {
	
	int t;
	ll n, x;
	
	scanf("%d", &t);
	
	for (int i = 1; i <= t; i++) {
		fastRead(&n);
		x = (ll)sqrt(n);
		printf("Case %d: %s\n", i, ((x*x == n)? "Yes" : "No"));
	}
	return 0;
}

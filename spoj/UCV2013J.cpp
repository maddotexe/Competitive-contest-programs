#include <iostream>
#include <cstdio>

using namespace std;

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

int a[1000];
void pre()
{
	int x = 1, i = 1;;
	a[0] = 1;
	do {
		x *= 2;
		a[i] = a[i-1] + x;
	} while(a[i++] < 1000000);
}
	

int main()
{
	pre();
	int n, x, i;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		int s = 0;
		for (i = 0; a[i] < n; i++);
		
		int y = a[i - 1] - ((a[i] - n) / 2);
		
		for (int i = 0; i < y; i++) {
			fastRead(&x);
		}
		
		for (int i = y; i < n; i++) {
			fastRead(&x);
			s += x;
		}
		
		printf("%d\n", s);
	}
	return 0;
}
	

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

int main()
{
	int n, x, y, g, h;
	int max = g = h = 0;
	for (int i = 0; i < n; i++) {
		fastRead(&x);
		fastRead(&y);
		g += x;
		h += y;
		
		if (g < h) {
			x = g - h;
			y = 2;
		} else {
			x = h - g;
			y = 1;
		}
		
		if (max < x) {
			max = x;
			d = y;
		}
	}
	
	cout << d << endl;
	
	return 0;
}
		

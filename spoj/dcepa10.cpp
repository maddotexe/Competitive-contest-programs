#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

/*inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}*/



int main()
{
	int t;
	int n, i, j, c;
	map <long long int, int> m;
	map <long long int, int>::iterator it;
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		long long int med, x;
		m.clear();
		for (i = 0; i < n ;i++) {
			cin >> x;
			m[x]++;
		}
		c = 0;
		for (it = m.begin(); it != m.end(); it++) {
			if (it->second > c) c = it->second;
		}
		
		c = n/2 + 1 - c;
		if (c <= 0) {
			printf("0\n");
		} else {
			printf("%d\n", c);
		}
		
	}
	
	return 0;
}


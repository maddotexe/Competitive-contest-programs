#include <iostream>

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
	int n, i, j;
	
	cin >> n;
	
	while (1) {
		if (n == 0) {
			return 0;
		}
		int a[n + 1];
		for (int i = 0; i < n; i++) {
			fastRead(&j);
			a[i + 1] = j;
		}
		
		for (j = 1; j <= n; j++) {
			if (j == a[a[j]]) {
				continue;
			} else break;
		}
		
		if (j == n + 1) {
			cout << "ambiguous\n";
		} else {
			cout << "not ambiguous\n";
		}
		cin >> n;
	}
	
	return 0;
}
	
	

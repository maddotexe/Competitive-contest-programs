#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

set <int> s;
int a[500001];

int pre() 
{
	a[0] = 0;
	
	for (int i = 1; i < 500001; i++) {
		int t = a[i] = a[i - 1] - i;
		
		a[i] += (t <= 0 || s.find(t) != s.end())? i << 1 : 0;
		s.insert(a[i]);
	}
}

int main()
{
	pre();
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == -1) {
			return 0;
		}
		
		printf("%d\n", a[n]);
	}
	
	return 0;
}

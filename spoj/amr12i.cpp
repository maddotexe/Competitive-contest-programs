#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int t;
	int n, k, c, f, g;
	string s;
	
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d%d", &n, &k);
		
		cin >> s;
		f = 0;
		g = 0;
		c = 0;
		for (int i = 0; i < n - 1 ; i++) {
			if (s[i] == s[i + 1]) {
				g++;
				if (g == k - 1) f = 1; 
			} else {
				c++;
				g = 0;
			}
			
		}
		if (f) 
		printf("%d\n", c + 1);
		else printf("-1\n");
	}
	return 0;
}

		

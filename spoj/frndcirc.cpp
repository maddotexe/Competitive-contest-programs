#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

int main()
{
	int a[100001];
	int b[100001];
	int c[100001];
	string s, s1;
	int t, n, d, g, g1;
	char ss[30], ss1[30];
	
	cin >> t;
	
	while (t--) {
		d = 1;
		g = 1;
		g1 = 1;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		map <string, int> m;
		scanf("%d", &n);
		getchar();
		//cout << n << endl;;
		for (int i = 0; i < n; i++) {
			scanf("%s%s", ss, ss1);
			s = ss;
			s1 = ss1;
			
			if (!m[s]) m[s] = d++;
			if (!m[s1]) m[s1] = d++;
			//cout << m[s] << " "<< m[s1];
			int x = m[s]; int y = m[s1];
			if(!a[x] && !a[y]) {
				a[x] = g;
				a[y] = g++;
				b[g - 1] = g1++;
				c[b[g-1]] += 2;
			}
			
			else if (!a[x] && a[y]) {
				a[x] = a[y];
				c[b[a[x]]]++;
			}
			
			else if (a[x] && !a[y]) {
				a[y] = a[x];
				c[b[a[x]]]++;
			}
			
			else {
				if (b[a[x]] != b[a[y]]) {
					if (y < x) {
						int l = y;
						y = x;
						x = l;
					}
					int tmp = b[a[y]];
					b[a[y]] = b[a[x]];
					a[y] = a[x];
					c[b[a[x]]] += c[tmp];
					
				}
			}
			
			
			printf("%d\n", c[b[a[x]]]);
		}
	}
	
		
	return 0;
}


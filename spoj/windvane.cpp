#include <iostream>
#include <map>
#include <cstdio>
#include <vector>

using namespace std;

struct node {
	unsigned a : 2;
	unsigned : 6;
};

int main()
{	
	int n, m2, t, d, x1, y1, x2, y2, z;
	
	char c;
	
	map<char, int> m;
	m['E'] = 0;
	m['W'] = 2;
	m['N'] = 3;
	m['S'] = 1;
	
	char m1[4];
	m1[0] = 'E';
	m1[1] = 'S';
	m1[2] = 'W';
	m1[3] = 'N';
	
	
	scanf("%d%d", &n, &m2);
	node v[n][m2];
	
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m2; j++) {
			c = getchar();
			v[i][j].a = m[c];
		}
	}

	scanf("%d", &t);
	
	while (t--) {
		getchar();
		c = getchar();
		
		if (c == 'C') {
			z = 1;
			scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &d);
			if (d == 0) {
				z = -1;
			}
			for (int i = x1 - 1; i < x2; i++) {
				for (int j = y1 - 1; j < y2; j++) {
						((v[i][j]).a) -= z;
				}
			}
			
		} else {
			scanf("%d%d", &x1, &x2);
			printf("%c\n", m1[v[x1 - 1][x2 - 1].a]);
		}
	}
	
	return 0;
	
}
	

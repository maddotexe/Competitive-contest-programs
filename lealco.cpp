#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
	int t, n, c, m, k, i, j, l, p, r, d, f, a[20];
	scanf("%d", &t);
 
	while (t--) {
		f = 0;
		scanf("%d%d%d", &n, &k, &m);
 
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
 
		if (m == 1) {
			printf("-1\n");
			continue;
		}
		for (i = 0; i <= n - k; i++) {
			c = d = 0;
              		for (p = i; p < i + k; p++) {
                  		if (d < a[p]) d = a[p];
              		}
              
              		for (j = 0; j <= k - m; j++) {
                  		for (l = 0; l < m; l++) {
					           if (a[i + j + l] != d) {
						          break;
					}
				}
				if (l == m) {
					for (p = 0; p < m - 1; p++) {
						if (a[i + j + l + p] != d + 1) {
							break;
						}
					}
					if (p == m - 1) {
						if (m == 2) {
							for (r = 1; r < m; r++) {
								if (a[i + j - r] != d + 1) {
									break;
								}
							}
							if (r == m) {
								a[i + j + l - 1]++;
								f++;
							} else {
								a[i + j + l - 2]++;
								f++;
							}
						} else {
							a[i + j + l - 2]++;
							f++;
						}
					} else {
						a[i + j + m - 1]++;
						f++;
					}
				}
              		}
          	}
 
		printf("%d\n", f);
	}
 
	return 0;
} 

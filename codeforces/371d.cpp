#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
	set <long long> s;
	set <long long>::iterator it, it1;
	long long n, q, x, y;
	cin >> n;
	long long a[n+1], b[n+1];
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		b[i] = 0;
		s.insert(i);
	}
	
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		scanf("%lld", &x);
		if (x == 1) {
			scanf("%lld%lld", &x, &y);
			long long i = x;
			it = s.find(x);
			if (it == s.end()) {
				it = s.upper_bound(x);
				if (it != s.end()) {
					while (y > 0 && it != s.end()) {
						if (y < a[*it] - b[*it]) {
							b[*it] += y;
							y = 0;
							it++;
						} else {
							y -= a[*it] - b[*it];
							b[*it] = a[*it];
							it1 = it;
							it++;
							s.erase(it1);
						}
					}
				}
			} else {
				if (it != s.end()) {
					while (y > 0 && it != s.end()) {
						if (y < a[*it] - b[*it]) {
							b[*it] += y;
							y = 0;
							it++;
						} else {
							y -= a[*it] - b[*it];
							b[*it] = a[*it];
							it1 = it;
							it++;
							s.erase(it1);
						}
					}
				}
			}
		} else {
			scanf("%lld", &x);
			it = s.find(x);
			if (it == s.end()) {
				printf("%lld\n", a[x]);
			} else {
				printf("%lld\n", b[x]);
			}
		}
	}
	
}

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, x, y, a, b;
	cin >> t;
	string ans;
	int c;
	while (t--) {
		cin >> n;
		cin >> a >> b;
		ans = "";
		c = 0;
		for (int i = 1; i < n; i++) {
			
			cin >> x >> y;
			if (x == a && y == b) {
				a = x;
				b = y;
				continue;
			}
			if (x > a) {
				while (a != b - 1) {
					if (a == x) break;
					ans += "L+";
					a++;
				}
				
				while (a != x) {
					ans += "R+L+";
					a++, b++;
				}
				
				while (b != y) {
					if (b < y) {
						ans += "R+";
						b++;
					} else {
						ans += "R-";
						b--;
					}
				}
				
			} else {
				
				while (a != b + 1) {
					if (a == x) break;
					ans += "L-";
					a--;
					
				}
				
				while (a != x) {
					ans += "R-L-";
					a--, b--;
				}
				
				while (b != y) {
					if (b < y) {
						ans += "R+";
						b++;
					} else {
						ans += "R-";
						b--;
					}
				}
			}
			a = x, b = y;
		}
		cout << ans.size() / 2 << endl;
		cout << ans << endl;
	}
	return 0;
}

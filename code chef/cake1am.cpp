#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

bool a[1010][1010];

int main()
{
	int t;
	cin >> t;
	int x1, x2, x3, x4, y1, y2, y3, y4;
	while (t--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;
		
		int ans = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3);
		
		int a = max(x1, x3);
		int b = min(x2, x4);
		int c = max(y1, y3);
		int d = min(y2, y4);
		
		if (b > a && d > c) {
			ans -= (a - b) * (c - d);
		}
		cout << ans << endl;
	}
	return 0;
}

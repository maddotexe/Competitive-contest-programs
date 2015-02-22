#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	
}

int main()
{
	int t, c, n, x, y;
	cin >> t;
	int c1, c2;
	while (t--) {
		cin >> n;
		c = c1 = c2 = 0;
		int cc = 0;
		int com = 0;
		int mcc = 0;
		for (int i = 0; i <n; i++) {
			cin >> x >> y;
			c1 = c2 = 0;
			while (x != y) {
				
				
				int m = max(x, y);
				int mm = min(x, y);
				if (m % mm != 0) {
					if (mm * 2 > m ) {
						c1++;
						c++;
						if(!c2) com++;
					} else if (mm * 2 < m) {
						c2++;
						cc++;
						c1 = 0;
					}
				} else {
					if (mm * 2 < m) {
						c2++;
						cc++;
						c1 = 0;
					} else {
						c1++;
						c++;
						if(!c2) com++;
					}
					break;
				}
				m = m % mm;
				x = m;
				y = mm;
			}
			if(c2) mcc++;
			//cout << endl;
		}
		
		if((com)&1) {
			if(mcc % 2 == 0) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			if(mcc % 2 != 0) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}	
		}
		
	//	cout << c << endl;
		//c1 += c2;
		//cout << c1 << " " << c2 << endl;
		
	}
	return 0;
}

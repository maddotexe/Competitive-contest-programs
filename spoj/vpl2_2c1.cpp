#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int a[1000001];
int b[1000001];

int main()
{
	map <char, int> m;
	m['G'] = 0;
	m['R'] = 1;
	m['Y'] = 2;
	m['B'] = 3;
	m['O'] = 4;
	int d = 1;
	string s;
	int c, t, max, r;
	
	cin >> t;
	
	while (t--) {
		cin >> c;
		cin >> s;
		max = 1;
		r = 1;
		int sum = 0;
		a[0] = 0;
		for (int i = 1; i < s.size(); i++) {
			sum += abs(m[s[i]] - m[s[i - 1]]);
			a[i] = sum;
		}
		int x = 0, y = 0;
		while(y <= s.size()) {
			if (abs(a[y] - a[x]) <= c) {
				y++;
			} else {
				x++;
			}
			if (abs(a[y] - a[x]) <= c && y < s.size()) {	
				r = y - x + 1;
				if (max < r) {
					max = r;
				}
			}
			
		}
		
		cout << "Scenario #" << d++ << ": " << max << endl;
	}
	
	return 0;
	
}

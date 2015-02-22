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
		b[0] = 0;
		for(int i = 1; i < s.size(); i++) {
			if (abs(m[s[i]] - m[s[i - 1]]) + b[i - 1] <= c) {
			 	b[i] = abs(m[s[i]] - m[s[i - 1]]) + b[i - 1];
			 	r++;
			 } else if (abs(m[s[i]] - m[s[i - 1]]) <= c) {
			 	b[i] = abs(m[s[i]] - m[s[i - 1]]);
			 	r = 2;
			 } else {
			 	r = 1;
			 	b[i] = 0;
			 }
			 
			 if (max < r) max = r;
		}
		cout << "Scenario #" << d++ << ": " << max << endl;
		
	}
	
	return 0;
}
	

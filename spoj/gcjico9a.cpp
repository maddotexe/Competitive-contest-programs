#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int t;
	
	long long int n = 1;
	long long int d = 2;
	int i;
	int c = 1;
	string s;
	int a[62];
	scanf("%d", &t);
	
	while (t--) {
		map <char, int> m;
		d = 1;
		i = 1;
		cin >> s;
		m[s[0]] = 1;
		a[0] = 1;
		n = 0;
		int a[62];
		while (s[i] == s[0]) {
			a[i] = 1;
			i++;
		}
		if (i < s.size()) {
			m[s[i]] = -1;
			a[i] = 0;
			i++;
			for (i; i < s.size(); i++) {
				if (!m[s[i]]) {
					m[s[i]] = ++d;
				}
				a[i] = ((m[s[i]] == -1) ? 0 : m[s[i]]);
			}	
		}
		d++;
		long long int g = 1;
		n = a[s.size() -1];
		for (int i = s.size() - 2; i >= 0; i--) {
			n += g * d * a[i];
			g *= d;
		}
		cout << "Case #" << c++ << ": " << n << endl;
	}
	
	return 0;
}
	

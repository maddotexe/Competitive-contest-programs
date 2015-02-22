#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define ull unsigned long long

ull mulmod(ull a, ull b, ull c)
{
	ull x = 0, y = a%c;
	while(b>0)
	{
		if(b&1) x = (x+y)%c;
		y = (y<<1)%c;
		b = b>>1;
	}
	return x;
}

int main()
{
	int t, n, i, j;
	
	cin >> t;
	
	ull a, b, c, l[1010], ans, pm, ps;
	string s;
	
	while (t--) {
		cin >> n;
		for (int x = 0; x < n; x++) {
			cin >> l[x];
		}
		cin >> a >> b >> c;
		bool f = true;
		i = 0, j = n - 1;
		cin >> s;
		ps = 0;
		pm = 1;
		for (int x = 0; x < s.size(); x++) {
			if (s[x] == 'R') {
				f = !f;
			} else if ( s[x] == 'A') {
				ps = (ps + a) % c;
			} else {
				pm = mulmod(pm, b, c);
				ps = mulmod(ps, b, c);
			}
			if (f) {
				ans = mulmod(l[i], pm, c);
				ans = (ans + ps) % c;
				i++;
			} else {
				ans = mulmod(l[j], pm, c);
				ans = (ans + ps) % c;
				j--;
			}
			cout << ans << " ";
		}
		cout << endl;
		
	}
	
}

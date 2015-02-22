#include<bits/stdc++.h>

using namespace std;

#define TRACE

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)

#endif


int abs(int x) {if(x < 0) return -x; return x;}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	int n, m;
	string s;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		cin >> s;
		int k = 0, ans = 0, cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (cnt != m) {
				if (s[i] == 'R') cnt++;
			}
			
			if (cnt == m) {
				int a = 1, b = 1;
				while (k < i && s[k] != 'R') {
					k++;
					a++;
				}
				while (i + 1 < s.size() && s[i + 1] != 'R') {
					i++;
					b++;
				}
				//trace2(a, b);
				ans += a * b;
				cnt--;
				k++;
			}
			
		}
		cout << ans << " ";
		k = 0, ans = 0, cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (cnt != n) {
				if (s[i] == 'K') cnt++;
			}
			
			if (cnt == n) {
				int a = 1, b = 1;
				while (k < i && s[k] != 'K') {
					k++;
					a++;
				}
				while (i + 1 < s.size() && s[i + 1] != 'K') {
					i++;
					b++;
				}
			//trace2(a, b);
				ans += a * b;
				cnt--;
				k++;
			}
			
		}
		
		cout << ans << endl;
	}
	return 0;
}



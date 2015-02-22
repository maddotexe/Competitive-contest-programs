#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	
	int t, n, d;
	string s, s1;
	
	cin >> t;
	
	int a[26];
	int b[26];
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		d = 0;
		while (d != 2) {
			cin >> s;
			int i = 0;
			int l = s.length();
			while (i < l) {
				a[(s[i] - 97)]++;
				i++;
			}
			d++;
		}
		
		cin >> n;
		
		while (n--) {
			cin >> s;
			int i = 0;
			int l = s.length();
			while (i < l) {
				b[(s[i] - 97)]++;
				i++;
			}
		}
		int i;
		for (i = 0; i < 26; i++) {
			if (b[i] > a[i]) {
				break;
			}
		}
		
		if (i != 26) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}
	

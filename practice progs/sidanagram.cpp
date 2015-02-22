#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	string s, ss;
	cin >> n;
	
	while (n--) {
		cin >> s >> ss;
		sort(s.begin(), s.end());
		sort(ss.begin(), ss.end());
		if (s.size() != ss.size()) {
			cout << "NO\n";
			continue;
		}
		bool f = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ss[i]) {
				f = 0;
				break;
			}
		} 
		if (f) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}



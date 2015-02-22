#include<bits/stdc++.h>

using namespace std;

map<char, int> m, mm;

int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	int n;
	cin >> n;
	
	while (n--) {
		cin >> s;
		m.clear();
		mm.clear();
		long long ans = 0, c = 0;
		for (int i = 0; i < s.size(); i++) {
			ans += (long long)m.size() + c;
			m[s[i]]++;
			
			if (m[s[i]] > 1 && !mm[s[i]]) {
				mm[s[i]]++;
				c++;
			}
			
		}
		cout << ans << endl;
	}
	return 0;
}



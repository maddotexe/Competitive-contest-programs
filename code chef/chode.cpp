#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, char> p, pair<int, char> p1) 
{
	return (p.first < p1.first);
}

bool check(char c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) 
		return true;
	return false;
}

int main()
{
	int t;
	string s, s1;
	
	cin >> t;

	vector< pair<int, char> > v;
	getchar();
	while (t--) {
		
		getline(cin, s);
		getline(cin, s1);
		map<char, char> m;
		v.clear();
		for (int i = 0; i < 26; i++) {
			v.push_back(pair<int, char> (0, char(i + 97)));
		}
		for (int i = 0; i < s1.size(); i++) {
			if (check(s1[i])) {
			
				v[(int)(tolower(s1[i])) - 97].first++;
				

			}
		}
		sort(v.begin(), v.end());
		/*for (int i = 0; i < 26; i++) {
			cout << v[i].second << "  " << v[i].first << endl;;
		}
		*/
		for (int i = 25; i >= 0; i--) {
			m[v[i].second] = s[i];
			//cout << v[i].second << " " << s[i] << endl;
			
		}
		
		for (int i = 0; i < s1.size(); i++) {
			if (check(s1[i])) {
				if (s1[i] >= 65 && s1[i] <= 90) {
					cout << char(m[tolower(s1[i])] - 32);
				} else {
					cout << m[s1[i]];
				}
			} else {
				cout << s1[i];
			}
		}
		cout << endl;
	}
}

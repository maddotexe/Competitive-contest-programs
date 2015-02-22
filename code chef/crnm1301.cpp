#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool myfunc(string s, string s1) {
	string s2;
	if (s.size() ==  s1.size()) {
		if ( s < s1)
		return true;
		return false;
	}
	int t, f = 1;
	//cout << s << " " << s1 << endl;
	if(s.size() < s1.size()){
		t = s.size();
		s2 = s1;
		s1 = s;
		s = s2;
		f = 0;
	} else {
		t = s1.size();
	}
	int i = 0;
	while (i < t) {
		if (s[i] == s1[i]) {
			i++;
		} else if (s[i] < s1[i]) {
	//		cout << s << " 2 " <<s1 << endl;
			return false;
		} else {
	//		cout << s << " 3 " <<s1 << endl;
			return true;
		}
	}
	i = 0;
	while (s[t] == s[i] && t != s.size()) {
		i++;
		t++;
	}
	if (s[t] > s[i]  && s1[s1.size() - 1] > s[t]) {
		if (f == 1) {
			return false;
		} else {
			return true;
		}
	//	cout << s << " 4 " <<s1 << endl;
		
	} else {
		if (f == 0) {
			return false;
		} else {
			return true;
		}
	//	cout << s << " 5 " <<s1 << endl;
		return false;
	}
}

int main()
{
	int n, t;
	string s;
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		long long int b[n];
		vector <string> v;
		
		for (int i = 0; i < n ; i++) {
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end(), myfunc);
		
		for (int i = n - 1; i >= 0; i--) {
			cout << v[i];
		}
		cout << endl;
	}
	
	return 0;
}

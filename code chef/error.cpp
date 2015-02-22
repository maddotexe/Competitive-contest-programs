#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int t;
	string s;
	
	cin >> t;
	bool f;
	while (t--) {
		cin >> s;
		f = false;
		for (int i = 2; i < s.size(); i++) {
			if ((s[i-2] == '1' && s[i-1] == '0' && s[i] == '1') || (s[i-2] == '0' && s[i-1] == '1' && s[i] == '0')) f = true;
			if (f) break;
		}
		if (f) {
			cout << "Good\n";
		} else {
			cout << "Bad\n";
		}
	}
}

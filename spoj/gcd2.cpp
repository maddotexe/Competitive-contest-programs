#include <iostream>
#include <string>

using namespace std;

int final(string s, int n) {
	int r = 0;
	for (int i = 0; i < s.size(); i++) {
		r = (s[i] - 48) + r * 10 ;
		r %= n;
	}
	
	return r;
}

int gcd(int n, int m) {
	if (m == 0) {
		return n;
	}
	return gcd(m, n % m);
}

int main()
{
	int t;
	
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		
		if (n == 0) {
			cout << s << endl;
		} else if (s[0] == '0') {
			cout << n << endl;
		} else {
			cout << gcd(n, final(s, n)) << endl;
		}
		
	}
	
	return 0;
}

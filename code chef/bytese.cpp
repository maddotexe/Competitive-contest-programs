#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t,  i, j, k, m;
	cin >> t;
	string s, a, b;

	
	while (t--) {
		cin >> s;
		a = "";
		a += s[0];
		b = "";
		j = 0;
		k = 0;
		m = 1;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == a[j]) {
				b += s[i];
				j++;
			} else {
				a += s[i];
				m++;
			}
		}
		if (a == b) {
			cout << a << endl;
		} else {
			cout  << "Twins don't exist\n";
		}
		
	}
	return 0;
}
				

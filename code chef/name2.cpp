#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string s1, s2, s;
	
	cin >> n;
	
	while (n--) {
		cin >> s1 >> s2;
		int l1 = s1.length();
		int l2 = s2.length();
		if (l1 > l2) {
			s = s1;
			s1 = s2;
			s2 = s;
		}
		l1 = s1.length();
		l2 = s2.length();
		int i = 0, j = 0, d = 0;
		while (i < l1 && j < l2) {
			if (s1[i] == s2[j]) {
				i++;
				d++;
			}
			j++;
			
		}
		if (d == l1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		
	}
	
	return 0;
}
		

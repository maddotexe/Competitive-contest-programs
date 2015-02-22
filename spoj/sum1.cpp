#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long int n, t, s, m;
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		
		if (n <= 3) {
			cout << 0 << endl;
			continue;
		} else if (n <= 5) {
			cout << 3 << endl;
			continue;
		} else {
			
			s = 0;
			m = (n - 1) / 3;
			s = (m * (6 + (m - 1) * 3)) / 2;
			m = (n - 1) / 5;
			
			s += (m * (10 + (m - 1) * 5)) / 2;
			if (n > 15) {
				m = (n - 1) / 15;
				s -= (m * (30 + (m - 1) * 15)) / 2;
			}
			
			cout << s << endl;
		}
		
	}
	return 0;
}

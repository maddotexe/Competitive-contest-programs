#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
	int n, t, i, a, b;
	
	
	cin >> t;
	int d = 1;
	while (t--) {
		stack <int> s;
		cin >> n;
		cin >> a;
		s.push(a);
		int c = 1;
		if (n < 11) {
			cout << "Case #" << d++ << ": go home!";
			continue;
		}
		for (i = 1; i < n; i++) {
			cin >> b;
			if ((c + n - i) == 11) {
				break;
			}
			
			if (b >= a) {
				s.push(b);
				a = b;
				c++;
			} else {
				while (s.top() < b && (c + n - i) > 11) {
					s.pop();
					c--;
				}
				s.push(b);
				c++;
			}
			
		}
		int w[s.size()];
		int k = s.size() - 1;
		while (!s.empty()) {
			w[k--] = s.top();
			s.pop();
		}
		cout << "Case #" << d++ << ":";
		if (i == n) {
			for (int j = 0; j < s.size(); j++) {
				cout << " " << w[i] ;
			}
		} else {
			for (int j = 0; j < s.size(); j++) {
				cout << " " << w[i] ;
			}
			for (int j = i; j < n; j++) {
				cin >> b;
				cout << " " << b ;
			}
		}
		cout << endl;
	}
	return 0;
}
			
	

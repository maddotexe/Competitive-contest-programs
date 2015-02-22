#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;


int main()
{
	int n;
	int t, h;
	string s;
	
	
	scanf("%d", &t);
	
	while (t--) {
		cin >> s;
		int i = 0;
		n = 0;
		h = -1;
		while (i < s.size() - 2) {
			if (s[i + 1] == 'n') {
				n++;
				if (h < n) {
					h = n;
				}
				i++;
				
			//	cout << "n = " << n  << "h = " << h << endl;
				continue;
			}
			if (s[i + 1] == 'l' && s[i + 2] == 'n') {
				n++;
				if (h < n) {
					h = n;
				}
				i += 2;
			//	cout << "n = " << n  << "h = " << h << endl;
				continue;
			}
			
			if (s[i + 1] == 'l' && s[i + 2] == 'l') {
				n = 0;
			//	cout << "n = " << n << endl;
				i += 2;
			}
		}
		
		printf("%d\n", h + 1);
	}
	
	return 0;
}

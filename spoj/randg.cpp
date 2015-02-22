#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n, r, g, pos;
	string s;
	while (cin >> s) {
		r = 0;
		g = 0;
		vector <int> rr(51);
		vector <int> gg(51);
		
		int i = 0; 
		while (s[i] == 'R' && i < s.size()) i++;
		while (s[i] == 'G' && i < s.size()) i++;
		if(i == s.size()) {
			cout << 0 << endl;
		} else {
			for (int i = 0; i < s.size(); i++) {
				if(s[i] == 'R') {
					r++;
				} else {
					g++;
				}
				
				rr[i] = r;
				gg[s.size() - 1 - i] = g;
			}
			int min = 9999999;
			for (int i = 0; i < s.size(); i++) {
				if (g - gg[i] + r - rr[i] < min) {
					min = g - gg[i] + r - rr[i];
				}
			}
			
			cout << min << endl;
		}
}
	
	return 0;
}

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	string s;
	
	int k = 0;
	
	int n, d, j;
	
	cin >> n;
	
	cin >> s;
	
	d = 0;
	for (int i = s.size() - 1 ; i >= 0;) {
		j = 0;
		while (s[i] == 'B' && k == 0) {
			j++;
			i--;
		}
		
		while (s[i] == 'A' && k == 1) {
			j++;
			i--;
		}
		
		
		if (j == 1) {
			d++;
		} else if (j > 1) {
			d++;
			if (k == 0) {
				k = 1;
			} else {
				k = 0;
			}
		} else {
			i--;
		}
	}
	
	cout << d << endl;
	return 0;
}
		

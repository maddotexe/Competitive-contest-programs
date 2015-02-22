#include <iostream>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int s;
	map<char, int> m;
	m['A'] = 1;
	m['B'] = 2;
	m['D'] = 1;
	m['O'] = 1;
	m['P'] = 1;
	m['Q'] = 1;
	m['R'] = 1;
	
	char ch;
	
	int n;
	
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		int c = 0;
		while (1) {
			ch = getchar_unlocked();
			if (ch == '\n') break;
			c += m[ch];
		}
		
		cout << c << endl;
	}
	
	return 0;
}
		

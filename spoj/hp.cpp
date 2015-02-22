#include <map>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	map <string, int> m;
	int c;
	m["\\0\\"]++;
	m["/0/"]++;
	m["|0|"]++;
	m["\\0/"]++;
	
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		c = 0;
		for (int i = 0; i < s.size() - 1;) {
			if (m[s.substr(i, 3)]) {
				i += 3;
				c++;
			} else {
				i++;
			}
		}
		if (c)
			cout << c << endl;
		else 
			cout << "That Bad Party xD\n";
	}
	
}

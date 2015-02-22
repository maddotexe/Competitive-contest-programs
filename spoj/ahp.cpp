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
	char c1;
	cin >> t;
	getchar();
	while (t--) {
		c1 = '9';
		s ="";
		
		while (1) {
			c1 = getchar();
			if (c1 == '\n') break;
			s += c1;
		}
		c = 0;
		for (int i = 0; i < s.size() - 2;) {
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
	
	for (map<string, int>::iterator it=m.begin(); it!=m.end(); ++it)
    		std::cout << it->first << " => " << it->second << '\n';
	
}

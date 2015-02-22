#include <iostream>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

int main()
{

	map<char, int> m;
	int t, i;
	map<char, int>::iterator it;
	string s;
	int c;	
	scanf("%d", &t);
	
	while (t--) {
		cin >> s;
		i = 0;
		while (s[i] != '\0') {
			m[s[i]]++;
			i++;
		}
		c = 0;
		it = m.begin();
		while (it != m.end()) {
			if (it->second & 1) {
				c += it->second / 2 + 1;
			} else {
				c += it->second / 2;
			}
			it++;
		}
		m.clear();
		
		printf("%d\n", c);
	}
	
	return 0;
}

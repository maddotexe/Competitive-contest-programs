#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

string r() {
	string s1 = "aeiou";
	int n = rand() % 4 + 8;
	string s = "";
	int k = 1;
	char c;
	for (int i = 0; i < n; i++) {
		if (k) {
			int g = (rand() % 26) + 97;
			k = 0;
			c = char(g);
		} else {
			c = s1[rand() % 5];
			k = 1;
		}
		
		s += c;
	}
	
	return s;
}

int main()
{
	int t, n, h, s, s1;
	s = 0; s1 = 1;
	cin >> t >> n >> h;
	
 	while (t--) {
		for (int i = 0; i < n; i++) {
			cout << r() << endl;
			fflush(stdout);	
		}
		scanf("%d", &s);
	}
}		
			

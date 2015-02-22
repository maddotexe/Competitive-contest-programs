#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int t, c;
	string s;
	
	cin >> t;
	
	while (t--) {
		c = 0;
		cin >> s;
		int v1[10010];
		vector <int> v(26);
		int g = 0;
		for (int i = 0; i < s.size(); i++) {
			int max;
			if (s[i] != '#') {
				v[s[i] - 97]++;
			}
			if (s[i] == '#' || i == s.size() - 1) {
				max = 0;
				c++;
				for (int j = 0; j < 26; j++) {
					//cout << v[j] << " ";
					if (max < v[j]) max = v[j];
					v[j] = 0;
				}
				//cout << endl << max << endl;
				v1[g++] = (max);
			}
			
		}
		if (s[s.size() - 1] != '#')
			c--;
		int max = 0;
		for (int i = 0; i < g - 2; i++) {
			//cout << v1[i] << endl;
			if (max < (v1[i] + v1[i + 1] + v1[i + 2] + v1[i + 3])) {
				max =  v1[i] + v1[i + 1] + v1[i + 2] + v1[i + 3];
			}
		}
		if (c < 3) {
			cout << "0\n";
		} else 
			cout << max + 3<< endl;
	}
	
	return 0;
}

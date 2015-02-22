#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

int score (string s) {
	int l = s.size();
	if(l <= 4) {
		l = 1;
	} else if (l == 5) {
		l = 2;
	} else if (l == 6) {
		l = 3;
	} else if (l == 7) {
		l = 5;
	} else {
		l = 11;
	}
	
	return l;
}


int main()
{
	int t, n, i, j, k, max, sum;
	string s3, s4;
	map <string, int> m;
	vector <vector <string> > v;
	vector <string> v1;

	cin >> n;
	getchar();
	for (int j = 0; j < n; j++) {
		getline(cin, s3);
		k = 0;
		s4 = "";
		while (k < s3.size()) {
			if (s3[k] == ' ') {
				v1.push_back(s4);
				m[s4]++;
				s4 = "";
			} else {
				s4 += s3[k];
			}
			if (k == s3.size() - 1) {
				v1.push_back(s4);
				m[s4]++;
			}
			k++;
		}
		
		v.push_back(v1);
		v1.clear();
		s3 = "";
	}
	max = 0;
	for (int i = 0; i < v.size(); i++) {
		sum = 0;
		for (int j = 0; j < v[i].size(); j++) {
			if (m[v[i][j]] > 1) {
				continue;
			} else {
				sum += score(v[i][j]);
			}
		}
		if (max < sum) {
			max = sum;
		}
	}
	
	cout << max << endl;
	
	return 0;
}
				
			

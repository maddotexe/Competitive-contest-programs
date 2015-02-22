#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string ifpos = "000+-0-+";
	string ifneg = "000-+0+-";

	string s;
	cin >> s;

	string sn = "00000000";
	
	int ctr = 0;
	int s_sz = s.size();
	vector<int> v;
	for (int i = 0; i < s_sz; i++) {
		if (s[i] == '0') {
			ctr++;
			if (ctr == 8) {
				v.push_back(i-7);
				ctr = 0;
			}
		} else {
			ctr = 0;
		}
	}
	
	int k = 1;
	int j = 0;
	string sm = "";
	for (int i = 0; i < s_sz; i++) {
		if ((! v.empty()) && v[j] == i) {
			if (i == 0) {
				sm += ifpos;
			} else {
				if (sm[i-1] == '+') {
					sm += ifpos;
				} else {
					sm += ifneg;
				}
			}
			j++;
			i += 7;
			continue;
		} 
		if (s[i] == '0') {
			sm += '0';
		} else {
			if (k) {
				sm += '+';
			} else {
				sm += '-';
			}
			k++;
			k %= 2;
		}
	}
	cout << sm << endl;

	return 0;
}

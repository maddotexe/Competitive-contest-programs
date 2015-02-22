#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

inline void _max(int &a, int &b)
{
	if (a < b) {
		a = a + b;
		b = a - b;
		a = a - b;
	}
}

int main()
{
	string ifposo = "000V";
	string ifnego = "000V";
	string ifpose = "B00V";
	string ifnege = "B00V";

	string s;
	cin >> s;

	string sn = "00000000";
	
	int ctr = 0;
	int s_sz = s.size();
	vector<int> v;
	for (int i = 0; i < s_sz; i++) {
		if (s[i] == '0') {
			ctr++;
			if (ctr == 4) {
				v.push_back(i-3);
				ctr = 0;
			}
		} else {
			ctr = 0;
		}
	}
	
	int k = 1;
	int j = 0;
	string sm = "";
	int np = 0;
	int nn = 0;
	for (int i = 0; i < s_sz; i++) {
		if ((! v.empty()) && v[j] == i) {
			if (i == 0) {
				sm += ifposo;
			} else {
				if (sm[i-1] == '+') {
					_max(nn, np);
					if ((nn-np) % 2) {
						sm += ifposo;
					} else {
						sm += ifpose;
					}
				} else {
					_max(nn, np);
					if ((nn-np) % 2) {
						sm += ifnego;
					} else {
						sm += ifnege;
					}
				}
				nn = 0;
				np = 0;
			}
			j++;
			i += 3;
			continue;
		} 
		if (s[i] == '0') {
			sm += '0';
		} else {
			if (k) {
				sm += '+';
				np++;
			} else {
				sm += '-';
				nn++;
			}
			k++;
			k %= 2;
		}
	}
	cout << sm << endl;

	return 0;
}

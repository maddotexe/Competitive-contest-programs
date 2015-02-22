#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class EllysSubstringSorter {
public:
	string getMin(string, int);
};

string EllysSubstringSorter::getMin(string s, int l) {
	vector <string> v;
		for (int i = 0; i < (int) s.size() - l +1; i++) {
			string s1 = s.substr(i, l);
			sort(s1.begin(), s1.end());
			string s2 = s.substr(0, i) + s1 + s.substr(i + l, s.size());
			//cout << s2 << endl;
			v.push_back(s2);
		}
		
		sort(v.begin(), v.end());
		//cout << v[0];
		return v[0];
}


//Powered by [KawigiEdit] 2.0!

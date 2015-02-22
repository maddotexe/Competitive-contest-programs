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

class WakingUp {
public:
	int maxSleepiness(vector <int>, vector <int>, vector <int>, int);
};

int WakingUp::maxSleepiness(vector <int> p, vector <int> s, vector <int> v, int d) {
	bool f = false, f1 = false;
	int ss = 0, ans = 0;
	for (int i = 1; i <= 2520; i++) {
		ss += d;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == i) {
				ss -= v[j];
				s[j] += p[j];
			}
		}
		
		ans = min(ans, ss);
	}
	
	if (ss < 0) {
		return -1;
	} 
	return max(-ans, 0);
		
}


//Powered by [KawigiEdit] 2.0!

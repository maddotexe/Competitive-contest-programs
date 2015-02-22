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

class FizzBuzzTurbo {
public:
	vector <long long> counts(long long, long long);
};

vector <long long> FizzBuzzTurbo::counts(long long a, long long b) {
	long long aa[]= {3, 5, 15};
	vector <long long> v;
	long long a1, b1;
	for (int i = 0; i < 3; i++) {
		a1 = a;
		b1 = b;
		
		while (b1 % aa[i] != 0) {
			b1--;
		}
		
		while (a1 % aa[i] != 0) {
			a1++;
		}
		if (b1 < a1) {
			v.push_back(0);
			continue;
		}
		v.push_back(1 + ((b1 - a1) / aa[i]));
	}
	v[0] -= v[2];
	v[1] -= v[2];
	return v;
}


//Powered by [KawigiEdit] 2.0!

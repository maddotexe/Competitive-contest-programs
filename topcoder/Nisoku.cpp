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
#include <cstring>

using namespace std;

#define eps 1e-9

class Nisoku {
public:
	double dp[51];
	double solve(int pos, vector <double> v) {
	cout << pos << endl;
		if (pos == v.size() - 1) {
			double x = v[0];
			for (int i = 0; i < v.size(); i++) {
				if (v[i] > x) x = v[i];
			}
			return x;
		}
		if (dp[pos] - 0.0 > eps) return dp[pos];
		double ans = 0.0;
		for (int i = 0; i < v.size(); i++) {
			if (i != pos && (v[i] - 0.00 > eps)) {
				double x = v[pos];
				v[pos] = 0.0;
				double y = v[i];
				v[i] = x * v[i];
				ans = max(ans ,solve(pos + 1, v));
				v[i] = x + y;
				ans = max(ans, solve(pos + 1, v));
				v[pos] = x;
				v[i] = y;
			}
		}
		
		return dp[pos] = ans; 
	}
	double theMax(vector <double>);
};

double Nisoku::theMax(vector <double> cards) {
	memset(dp, 0.0, sizeof(dp));
	double ans = solve(0, cards);
	for (int i = 0; i < cards.size(); i++) max (ans, dp[i]);
	return ans;
}


//Powered by [KawigiEdit] 2.0!

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

class PirateTreasure {
public:
	double getDistance(vector <int>, vector <string>);
};

double PirateTreasure::getDistance(vector <int> d, vector <string> s) {
	double ans = 0.0;
	int x = 0, y = 0;
	for (int i = 0; i < d.size(); i++) {
		if (s[i] == "EAST") {
			x += d[i];
		} else if (s[i] == "NORTH") {
			y += d[i];
		} else if (s[i] == "WEST") x-=d[i];
		  else if (s[i] == "SOUTH") y-=d[i];
		  else if (s[i] == "NORTHEAST") {
		  	x+=(0.5 * pow(d[i], 2)), y+=(0.5 * pow(d[i], 2));
		} else if (s[i] == "NORTHWEST") {
		  	x-=(0.5 * pow(d[i], 2)), y+=(0.5 * pow(d[i], 2));
		} else if (s[i] == "SOUTHEAST") {
		  	x+=(0.5 * pow(d[i], 2)), y-=(0.5 * pow(d[i], 2));
		} else if (s[i] == "SOUTHWEST") {
		  	x-=(0.5 * pow(d[i], 2)), y-=(0.5 * pow(d[i], 2));
		} 
	}
	
	ans = (double) sqrt((double)(x * x) + (double)(y * y));
	return ans;
}


//Powered by [KawigiEdit] 2.0!

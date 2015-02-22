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

class TurningLightOn {
public:
	int minFlips(vector <string>);
};

int TurningLightOn::minFlips(vector <string> v) {
 int c = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		for (int j = v[i].size() - 1; j >= 0; j--) {
			if (v[i][j] == '0') {
				c++;
				for (int k = 0; k <= i; k++) {
					for (int l = 0; l <= j; l++) {
						if (v[k][l] == '1') v[k][l] = '0';
						else v[k][l] = '1';
					} 
				}
			}
		}
	}
	
	return c;
}

//Powered by [KawigiEdit] 2.0!

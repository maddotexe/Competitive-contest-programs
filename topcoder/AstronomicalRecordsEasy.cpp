
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class AstronomicalRecordsEasy {
	public:
	int minimalPlanets(vector <int> a, vector <int> b) {
		int ma = 0;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				int c = 0;
				for (int x = 0 ; x < a.size(); x++) {
					for (int y = 0; y < b.size(); y++) {
						if (a[i] * b[y] == b[j] * a[x]) c++;
					}
				}
				ma = max(ma, c);
			}
		}
		return a.size() + b.size() - ma;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

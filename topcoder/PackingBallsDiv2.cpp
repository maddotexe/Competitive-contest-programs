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

class PackingBallsDiv2 {
public:
	int minPacks(int, int, int);
};

int PackingBallsDiv2::minPacks(int r, int g, int b) {
	int c = 0;
	c += r / 3;
	r %= 3;
	c += g / 3;
	g %= 3;
	c += b / 3; 
	b %= 3;
	
	int x = min(r, (min(g, b)));
	c += x;
	g -= x;
	r -= x;
	b -= x;
	if (r == 0) {
	 x = min(g, b);
	} else if (b == 0) {
		x = min(r, g);
	} else {
		x = min(r, b);
	}
	//x = min(r, (min(g, b)));
	c += x;
	g -= x;
	r -= x;
	b -= x;
	
	c += max(r, (max(g, b)));
	
	return c;
	
	 
}


//Powered by [KawigiEdit] 2.0!

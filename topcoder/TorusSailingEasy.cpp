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
#define eps 1e-8
using namespace std;

class TorusSailingEasy {
public:
	double dp[11][11][50000];
	int sx, sy, n, m;
	double expectedTime(int, int, int, int);
	
	double solve(int x, int y, int c)
	{
		if (c == 50000) return 0;
		if (x == sx && y == sy) return 0;
		if (dp[x][y][c] != -1) return dp[x][y][c];
		
		double ans = 0.0;
		
		ans += 0.5 * (1+solve((x+1) % n, (y + 1) % m, c+1)) + 0.5 * (1+solve((x-1+n) % n, (y-1+m)%m, c+1));
		return dp[x][y][c] = ans;
	}
};

double TorusSailingEasy::expectedTime(int N, int M, int goalX, int goalY) {
	memset(dp, -1.0, sizeof(dp));
	sx = goalX, sy = goalY, n = N, m = M;
	double ans = solve(0, 0, 0);
	if (50000 - ans < eps) return -1;
	return ans;
}


//Powered by [KawigiEdit] 2.0!

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

class JumpingBoard {
public:
	int dp[51][51], n, m;
	vector <string> b;
	bool f;
	int solve(int x, int y, int curr) {
		if (x >= n || x < 0 || y < 0 || y >= m || b[x][y] == 'H') return 0;
		if (curr > 5000) {f = false ;return 0;}
		if (dp[x][y] != -1) return dp[x][y];
		int ans = 0;
		
		ans = max(ans, solve(x + (b[x][y] - '0'), y, curr + 1) + 1);
		ans = max(ans, solve(x, y + (b[x][y] - '0'), curr + 1) + 1);
		ans = max(ans, solve(x - (b[x][y] - '0'), y, curr + 1) + 1);
		ans = max(ans, solve(x, y - (b[x][y] - '0'), curr + 1) + 1);
		
		return dp[x][y] = ans;
	}
	int maxJumps(vector <string>);
};

int JumpingBoard::maxJumps(vector <string> v) {
	n = v.size();
	m = v[0].size();
	b = v;
	f = true;
	memset(dp, -1, sizeof(dp));
	int ans = solve(0, 0, 0);
	if (!f) return -1;
	return ans;
}


//Powered by [KawigiEdit] 2.0!

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
 
class BallsSeparating {
public:
  int minOperations(vector <int>, vector <int>, vector <int>);
};
int dp[60][1<<3];
int BallsSeparating::minOperations(vector <int> red, vector <int> green, vector <int> blue) {
  int n = (int)red.size(), i, j;
  for (i = 0; i <= n; i++){
      for (j = 0; j < 8; j++){
          dp[i][j] = 1<<30;
      }
  }
  dp[0][0] = 0;
  for (i = 0; i < n; i++){
      for (j = 0; j < 8; j++){
          dp[i + 1][j | 1] = min(dp[i + 1][j | 1], dp[i][j] + green[i] + blue[i]);
          dp[i + 1][j | 2] = min(dp[i + 1][j | 2], dp[i][j] + red[i] + blue[i]);
          dp[i + 1][j | 4] = min(dp[i + 1][j | 4], dp[i][j] + green[i] + red[i]);
      }
  }
  j = 0;
  for (i = 0; i < n; i++){
      if (red[i]) j |= 1;
      if (green[i]) j |= 2;
      if (blue[i]) j |= 4;
  }
  if (dp[n][j] == (1<<30)) dp[n][j] = -1;
  return dp[n][j];
}

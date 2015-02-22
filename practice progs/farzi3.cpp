#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n;
int a[5000055], b[5000055], c[5000055];
int dp[5000050][3][3];

int solve(int pos, int prev, int now)
{
    if(pos == n) return 0;
    if(pos == n-1) {
        if(now) {
            if(prev) {
                return b[pos];
            }
            else return a[pos];
        }
        else return 0;
    }
    if(dp[pos][prev][now] != -1) return dp[pos][prev][now];
    int ans = 0;
    if(!now) {
        if(prev) {
            ans = max(ans, solve(pos+1, 0, 1));
            ans = max(ans, solve(pos+1, 0, 0));
        } else {
            ans = max(ans, solve(pos+1, 0, 0));
            ans = max(ans, solve(pos+1, 0, 1));
        }
    }
    else {
        if(prev) {
            ans = max(ans, c[pos]+solve(pos+1, 1, 1));
            ans = max(ans, b[pos]+solve(pos+1, 1, 0));
        }
        else {
            ans = max(ans, a[pos]+solve(pos+1, 1, 0));
            ans = max(ans, b[pos]+solve(pos+1, 1, 1));
        }
    }
    return dp[pos][prev][now] = ans;
}

int main()
{
    while(scanf("%d",&n)!=EOF) {
        for(int i = 0; i <= n+1; i++) {
            dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;
        }
        for(int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        cout << max(solve(0, 0, 0) , solve(0, 0, 1)) << endl;
    }
    return 0;
}

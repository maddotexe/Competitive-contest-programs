#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[100000];
int main()
{
	int e, f, t, n;
	
	cin >> t;
	
	while (t--) {
		cin >> e >> f >> n;
		int w[n + 1], p[n + 1];
		
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		
		for (int i = 1; i <= n; i++) {
			cin >> p[i] >> w[i];
			if (dp[w[i]] == -1) {
				dp[w[i]] = p[i];
			} else {
				dp[w[i]] = min(dp[w[i]] , p[i]);
			}
		}
		
		for (int i = 0; i <= f-e; i++) {
			
				if (dp[i] == -1) {
					continue;
				}
			for (int j = 1; j <= n; j++) {
				if (i + w[j] <= f) {
					(dp[i+w[j]] == -1)? dp[i + w[j]] = dp[i] + p[j]:dp[i +w[j]] = min (dp[i+w[j]], dp[i] + p[j]);
				}
			}
		}
		if (dp[f - e] != -1)
		cout << "The minimum amount of money in the piggy-bank is " << dp[f-e] << "." << endl;
		else 
		cout << "This is impossible.\n";
	}
	
	return 0;
}

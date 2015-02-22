#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
long long int dp[10099];
long long int a[10010];
int main()
{
	int t, n, c = 1;
	
	cin >> t;
	
	while (t--) {
		scanf("%d", &n);
		
		for (long long int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);	
		}
		dp[0] = 0;
		dp[1] = a[0];
		for (long long int i = 1; i < n; i++) {
			dp[i+1] = max(a[i] + dp[i - 1], dp[i]);
		}
		cout << "Case " << c++ << ": " << dp[n] << endl;
	}
	return 0;
}


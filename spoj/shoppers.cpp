#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long int dp[1<<14][14];
int a[14][14];
int s[14];
int k, n, m;


long long int solve(int items, int seller, int mask)
{
	long long int t;
	if (items == k) return 1;
	if (seller == n) return 0;
	if (n - seller + items < k) return 0;
	if (dp[seller][mask] != -1) return dp[seller][mask];
	
	t = solve(items, seller + 1, mask);
	
	for (int i = 0; i < s[seller]; i++) {
		int y = a[seller][i];
		
		if(!(mask & (1<<y))) {
			t += solve(items+1, seller+1, mask | (1<<y));
		}
	}
	
	dp[seller][mask] = t;
	
	return t;
}

int main()
{
	int t;
	char x;
	cin >> t;
	
	while (t--) {
		
		
		memset(s, 0, sizeof(s));
		memset(dp, -1, sizeof(dp));
		
		scanf("%d%d%d", &n, &m, &k);
		
		for (int i = 0; i < n; i++) {
			getchar();
			for (int j = 0; j < m; j++) {
				scanf("%c", &x);
				
				if (x == '1') {
					a[i][s[i]++] = j;
				}
			}
		}
		
		printf("%lld\n", solve(0, 0, 0));
	}
	return 0;
}
		
		

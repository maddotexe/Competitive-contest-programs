#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define max(p, q) p > q ? p : q

int dp[1024][1024], match[1024][1024];

int main()
{
	int k, l, l1, i, j, p, q, z;
	string s, s1;
	
	scanf("%d", &k);
	
	while (1) {
		if(!k) {
			return 0;
		}
		cin >> s >> s1;
		l = s.size();
		l1 = s1.size();
		
		for (i = 0; i <= l; i++) {
		    for (j = 0; j <= l1; j++) {
		    	dp[i][j] = 0;
			match[i][j] = 0;
		    }
		}
		
		for (i = 1; i <= l; i++) {
			for (j = 1; j <= l1; j++) {
				match[i][j] = max(match[i - 1][j], match[i][j - 1]);
					
				if (s1[j - 1] == s[i - 1]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
					//match[i][j] = max(match[i][j], match[i - 1][j - 1] + 1);	
				} else {
					dp[i][j] = 0;
				}
				
				
				if(dp[i][j] >= k) { 
					for(int z = k; z <= dp[i][j]; ++z) {
						match[i][j] = max(match[i][j], match[i - z][j - z] + z);
					}
				}
			}
			
	}
		printf("%d\n", match[l][l1]);
			
		scanf("%d", &k);
	}
	
	
	return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

double dp[1001][10001];
double sink[1001];
int dis[1001];
int n, l, d; 

double solve(int pos, int curr, int tot)
{
	//cout << pos << " " << tot << endl;
	if (pos == n) {
		return 1.0;
	}	
	if (tot + l >= d) return 1.0;
	
	if (dp[pos][curr] > 0.00000) return dp[pos][curr];
	
	double ans = 0.0;
	int temp = 0;
	for (int i = pos; i < n; i++) {
		temp += dis[i];
		if (temp <= l) {
			double x = sink[i] * solve(i + 1, temp, tot + temp);
			if (x - ans > 0.000000) {
				ans = x;
			}
		} else {
			break;
		}
	}
	//cout << ans << endl;
	return dp[pos][curr] = ans;
}

int main()
{
    //cout << "Hello World!" << endl;
    
    cin >> n >> l >> d;
    for (int i = 0; i <= n; i++) {
    	for (int j = 0; j < l + 1; j++) {
    		dp[i][j] = 0.0;
    	}
    }
    for (int i = 0; i < n; i++) {
    	cin >> sink[i];
    }
    
    for (int i = 0; i < n; i++) {
    	cin >> dis[i];
    }
    
    for (int i = n - 1; i > 0; i--) {
    	dis[i] = dis[i] - dis[i-1];
    }
    
    
    double x = solve (0, 0, 0);
    if (x > 0.000000) {
    	printf("%.6lf\n", x);
    } else {
    	cout << "IMPOSSIBLE"<< endl;
    }
    return 0;
}


#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, k;
	int a[n];
	
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int dp1[n], dp2[n], pos1[n], pos2[n];
	
	int i = 0;
	int j = n - 1;
	int s = 0, s1 = 0;;
	while (i < k) {
		s += a[i];
		s1 += a[j];
		dp1[i++] = 0;
		dp2[j--] = 0;
		
	}
	dp1[k-1] = s;
	dp2[j+1] = s1;
	pos1[k-1] = 1;
	pos2[j+1] = n - k;
	for (int i = k; i < n; i++) {
		if (dp1[i-1] >= (dp1[i-1] - a[i-k] + a[i])) {
			dp1[i] = dp1[i-1];
			pos1[i] = pos1[i-1];
		} else {
			dp1[i] = dp1[i-1] - a[i-k] + a[i];
			pos1[i] = i - k + 1;
		}
	}
	
	for (int i = j; i >= 0; i--) {
		if (i <= k) {
			dp2[i] = 0;
			pos2[i] = -1;
		} else {
			if(dp2[i+1] > (dp2[i+1] - a[i+k] + a[i])) {
				dp2[i] = dp2[i+1];
				pos2[i] = pos2[i+1];
			} else {
				dp2[i] = dp2[i+1] - a[i+k] + a[i];
				pos2[i] = i; 
			}
		}
	}
	
	int max = 0, posi, posj;
	for (int i = 0; i < n; i++) {
		if (max < (dp1[i] + dp2[i])) {
			max = dp1[i] + dp2[i];
			posi = pos1[i];
			posj = pos2[i];
		}
	}
	
	cout << posi << " " << posj + 1 << endl;
}
		

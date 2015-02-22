#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long int a[10000005];
int main()
{
    int t;

    cin >> t;

    while(t--) {
        long long int n, k, val, sum;

        scanf("%lld%lld", &n, &k);

        sum = 0;
        a[0] = 0;
        int max = 0;
        for(int i = 1; i <= n; i++) {
                scanf("%lld", &val);
                sum += val;
                a[i] = sum;
        }
        int l = 1, r = 1;
        sum = 0;
        while (r <= n) {
        	if (a[r] - a[l - 1] <= k) {
        		sum = a[r] - a[l - 1];
        		if (max == r - l + 1) {
        			val = min(sum, val);
        		}
        		if(max < (r - l + 1)) {
        			max = r - l + 1;
        			val = sum;
        		
        		}
        		r++;
        		
        	} else {
        		
        		l++;
        	}
        }
        
        cout << val << " " << max << endl;

    }
}



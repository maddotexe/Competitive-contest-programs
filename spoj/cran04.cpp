#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long int k;
    int t;
    long long int n;
    
    long long int sum = 0, r;
    char s[1000010];
    
    scanf("%d", &t);
    
    while (t--) {
    	sum = 0;
        scanf("%lld%lld", &n, &k);
        scanf("%s", s);
        
        long long int i = 0;
        if (k == 0) {
        	while(i < n) {
        		int h = i;
        		while(s[i] == '0' && i < n) i++;
        		sum += (i - h) * (i - h + 1) / 2;
        		while(s[i] == '1' && i < n) i++;
        	}
        	printf("%lld\n", sum);
        	continue;
        }
        while(s[i] != '1'&& i != n) {
            i++;
        }
        int j = i;
        int c = 0;
        while(j < n && c != k) {
            if (s[j] == '1') c++;
            j++;
        }
        j--;
        if (c != k) {
            printf("0\n");
            continue;
        }
        r = i;
        while(j < n) {
            long long int m = j;
            while((r > 0) && (s[r - 1] == '0')) r--;
            
            while(m < n && s[m + 1] == '0') m++;
            sum += (i - r + 1) * (m - j + 1);
            
            if (j == n - 1) {
                break;
            }
            i++;
            j++;
            while(s[i] != '1') i++;
            r = i - r + 1;
            while(s[j] != '1' && j < n) j++;
        }
        printf("%lld\n", sum);
    }
}

#include <iostream>
#include <cstdio>
#include <algorithm>
 
unsigned long long int s[1000001], f[1000001];
 
using namespace std;
 
int main()
{
    int t, n, i, j, max, c;
    
    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        
        for (i = 0; i < n; i++) {
            scanf("%lld%lld", &s[i], &f[i]);
        }
        
        sort(s, s + n);
        sort(f, f + n);
        
        c = i = j = max = 0;
        
        while (i < n) {
              if (s[i] < f[j]) {
                       c++;
                       if (max < c) {
                               max = c;
                       }
                       i++;
              } else {
                     c--;
                     j++;
              }
        }
        
        printf("%d\n", max);
    }
    
    return 0;
}

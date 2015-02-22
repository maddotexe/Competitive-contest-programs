#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    
    cin >> n >> m >> k;
    
    int a[n];
    
    int i;
    
    for(i = 0 ; i < n; i++) {
          cin >> a[i];
    }
    
    sort(a, a + n);
    int f = 0;
    if (k == 1) {
          if (a[n-1] < m) {
                     cout << "-1";
                     return 0;
          }
    }
    for(i = n-1; i >= 0; i++) {
          if(m <= k) {
               cout << f;
              break;
          }
          else {
               f++;
               k--;
               m = m - a[i];
          }
    }
    
    return 0;
}
    

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    
    int t, f, n, m, k, i, j, c, d;
    
    scanf("%d", &t);
    
    while (t--) {
          f = 0;
          scanf("%d%d%d", &n, &k, &m);
          
          int a[n];
          
          for (i = 0; i < n; i++) {
              scanf("%d", &a[i]);
          }
          if (m == 1) {
                printf("-1\n");
                continue;
          }
          for (i = 0; i < n; i++) {
              c = 0;
             
              d = 0;
              for ( int p = i; p < i + k; p++) {
                  if ( d < a[p]) d = a[p];
              }
              
              for (j = i; j < i + k; j++) {
                  if (a[j] == d) {
                           c++;
                           
                           if (c == m) {
                               a[j]++;
                               c = 0;
                               f++;
                               break; 
                           }
                  } else {
                         c = 0;
                         break;
                  }
                  
              }
              if (i == j) {
                    i = j;
              } else
                    i = j - 1;
          }
          
          printf("%d\n", f);
    }
    
    return 0;
}

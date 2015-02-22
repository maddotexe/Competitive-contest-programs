#include <stdio.h>

int main()
{
    int i;
    int t;
    int t1;
    int n,j,k,d,b,y;
    scanf("%d", &t1);
    for( y = 1; y <= t1; y++) {
                scanf("%d", &n);
                if( n == 1) {
                    printf("Case #%d: 1\n", y);
                }
                else if( n ==2) {
                     printf("Case #%d: 2\n", y);
                }
                else {
                     n = n -2;
                     d = 0;
                     t = 3;
                     for( i = 2; ; i++) {          
                          for (k = 1; k < i; k++) {
                              for ( j = 1; j <= i; j++) {
                                  b = t;
                                  d++;
                                  if(d == n) break;
                              }
                              t++;
                              if(d == n) break;
                          }
                          if (d == n) break;
                     }
                     printf("Case #%d: %d\n", y, b);
                }
    }
    return 0;
}

#include <stdio.h>

int main()
{
    int n,m,t,i,x2,x1,y1,y2,c,j;
    scanf("%d", &t);
    while(t--) {
               scanf("%d%d", &n, &m);
               int a[n][2];
               for(i = 0; i < n; i++) {
                     scanf("%d%d", &a[i][0], &a[i][1]);
               }
               for(j = 0; j < m; j++) {
                     c=0;
                     scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                     for(i = 0; i < n; i++) {
                           if( a[i][0] <= x2 && a[i][0] >= x1) {
                               if(a[i][1] <= y2 && a[i][1] >= y1) {
                                          if((a[i][1] - y1) % (a[i][0] -x1) == 0) {
                                                      if((y2 - y1) % (x2 -x1) == 0) {
                                                             c++;
                                                      }
                                          }
                               }
                           }
                     }
                     printf("%d\n", c);
               }
    }
    return 0;
}            

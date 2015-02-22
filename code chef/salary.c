#include <stdio.h>

int main()
{
    int t;
    int n;
    int min, c, i;
    scanf("%d", &t);
    
    while (t--) {
          scanf("%d", &n);
          
          int w[n];
          min = 11000;
          c = 0;
          for (i = 0; i < n; i++) {
              scanf("%d", &w[i]);
              
              if (min > w[i]) {
                      min = w[i];
              }    
          }
          
          for (i = 0 ; i < n; i++) {
              c = c + w[i] - min;
          }
          
          printf("%d\n", c);
    }
    
    return 0;
}

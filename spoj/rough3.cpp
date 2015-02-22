#include <stdio.h>
int main()
{
    int i,j,k,sum=0;
    int a[10];
    int t;
    for(i = 0; i < 10 ; i++) {
          scanf("%d", &t);
          for( j = 0; j < i; j++) {
               if (t > a[j]) {
                    for ( k = i;k > j; k--) {
                        a[k] = a[k-1];
                    }
                    break;
               }
          }
          a[j] = t;
    }
    for( i = 0 ; i < 10; i++) {
         if(sum + a[i] <= 100) {
                sum += a[i];
         }
    }
    printf("%d\n", sum);

    return 0;
}
          

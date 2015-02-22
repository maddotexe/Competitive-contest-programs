#include <stdio.h>
int main()
{
    long long int a ,b, c,i,d,a1,j;
    int t;
    scanf("%d", &t);
    while(t--) {
               scanf("%lld%lld%lld", &a, &b, &c);
               for( i = 1; ; i++)
               {
               if(2*c %i == 0) {
                      if((b-a) % (i-6) == 0) {
                               if((2*c/i) - ((b-a)/(i-6)) == a+b)
                         break;
                      }
               }
               }
               d = (b -a)/(i-6);
               a1 = a - 2*d;
               printf("%lld\n", i);
               for(j = 0; j < i; j++) {
                     printf("%lld ", a1+j*d);
               }
               printf("\n");
    }
    return 0;
}

#include <stdio.h>
int main()
{
    long long int a,b,s,d,n,a1,i;
    int t;
    scanf("%d", &t);
    while(t--)
    {
              scanf("%lld%lld%lld", &a, &b, &s);
              n = (2*s)/(a+b);
              d = (b-a)/(n-5);
              a1 = a- (2*d);
              printf("%d\n", n);
              for( i = 1; i <= n; i++)
              {
                   printf("%d ",a1+(i-1)*d);
              }
              printf("\n");
    }
    return 0;
}

#include <stdio.h>
int main()
{
    int a=0,c,b,i,t;
    b = 1;
    unsigned long long int l;
    scanf("%d",&t);
    while(t--)
    {
      a = 0;
      b = 1;
      scanf("%lld", &l);
      l %= 60;
      for(i = 1; i < l; i++)
          {
            c = a;
            a = (a + b)%10;
            b = c;
          }
          if (l== 0)
          a = 1;
      printf("%d\n", a);
    }
    return 0;
}

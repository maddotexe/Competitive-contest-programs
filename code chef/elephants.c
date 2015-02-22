#include <stdio.h>

int main()
{
    int t;
    unsigned long int n,c,sum,k;
    scanf("%d", &t);
    while(t--)
    {
              sum = 0;
              scanf("%lu %lu", &n, &c);
              while(n)
              {
                      scanf("%lu", &k); 
                      sum+=k;
                      n--;
              }
              if(sum > c)
                     printf("NO\n");
              else
                  printf("YES\n");
    }
    return 0;
}

#include <stdio.h>
#include <math.h>
int main()
{
    int t,i,j;
    scanf("%d", &t);
    while(t--)
    {
              scanf("%d", &i);
              j = sqrt(i);
              while(j >= 1)
              {
                      if(i%j == 0)
                      {
                             j = i/j - j;
                             break;
                      }
                      j--;
              }
              printf("%d\n", j);
    }
    return 0;
}

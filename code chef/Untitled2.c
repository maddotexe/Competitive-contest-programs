#include <stdio.h>
int main()
{
    int t,h,l,i;
    int j,n;
    int a[100000];
    scanf("%d", &t);
    while (t--)
    {
          l=0;
          h=0;
          scanf("%d", &n);
          for( i = 0; i < n; i++)
               scanf("%d", &a[i]);
               
          if(n == 1)
          {
               printf("UNFIT\n");
          
          }
          else
          {
             for( i = 0; i < n; i++)
             {
                  for ( j=i+1; j < n;j++)
                  {
                      l = a[j]- a[i];
                      if( h < l)
                      {
                          h = l;
                      }
                  }
             }
             if( h > 0)
             {
                 printf("%d\n", h);
             }
             else
             {
                 printf("UNFIT\n");
             }
          }
    }
    return 0;
}

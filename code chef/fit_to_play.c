#include <stdio.h>
int main()
{
    int t,h,l,i,hp,lp,p;
    int j,n,md;
    int a[100000];
    scanf("%d", &t);
    while (t--)
    {
          l=a[0];
          h=a[0];
          scanf("%d", &n);
          for( i = 0; i < n; i++)
               scanf("%d", &a[i]);
               
          if(n == 1)
          {
               printf("UNFIT\n");
          
          }
          else
          {
             for(i = 0; i < n; i++)
             {
                   if(a[i] > h)
                   {
                           h = a[i];
                           hp = i;
                   }
                   if(a[i] < l)
                   {
                           l = a[i];
                           lp = i;
                   }
             }
             if(hp > lp)
             {
                   printf("%d\n", h-l);
             }
             
             else
             {
                 l = 0;
                 for ( i = 0; i < hp; i++)
                 {
                     if(a[i] < l)
                   {
                           md = h - a[i];
                   }
                 }
                 h = a[lp];
                 for (i = lp; i < n; i++)
                 {
                     if(h < a[i] && (a[i] - l > md))
                     {
                          md = a[i] - l;
                     }
                 }
                 for ( i = lp ; i < hp ; i++)
                 {
                     for ( j=i+1; j < hp;j++)
                  {
                      p = a[j]- a[i];
                      if( md < p)
                      {
                          md = p;
                      }
                  }
                 }
                 printf("%d\n", md);
          }}
    }
    return 0;
}

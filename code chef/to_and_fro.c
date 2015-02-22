#include <stdio.h>

int main()
{
    int n, a[250][30],u,l,i,j,k,t;
    char b[5000];
    scanf("%d", &n);
    
    while ( n!=0)
    {
          getchar();
          u=0;
          gets(b);
          l = strlen(b);
          t = l/n;
          k = 0;
          for(i= 0; i < t; i++)
          {
                 if( u % 2 == 0)
                 {
                     for(j = 0; j < n ; j++)
                     {
                           a[i][j] = b[k];
                           k++;
                     }
                 }
                 else
                 {
                     for(j = n-1; j >= 0 ; j--)
                     {
                           a[i][j] = b[k];
                           k++;
                     }
                 }
                 u++;
          }
          for(i= 0; i < n; i++)
          {
                 for(j = 0; j < t ; j++)
                 {
                       printf("%c", a[j][i]);
                 }
          }
          printf("\n");
          scanf("%d", &n);
    }
    return 0;
}

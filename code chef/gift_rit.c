#include <stdio.h>

int main()
{
    int r, c, i ,j,m,t, l =99999999,n,p=0,k,g=-4;
    scanf("%d%d", &r,&c);
    long long int a[r][c];
    for ( i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for ( i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
    for( i =0 ;i < c; i++)
    {
         //n=0;
         m =-1;
       //  g = -4;
         for( j = 0 ; j < r; j++)
         {
              if(a[j][i] > m)
              {
                         m = a[j][i];
                         t = j;
                         
                         
              }
         }
         printf("%d  ", m);
         
  /*       for( k = 0 ; k < c; k++)
         {
              if(a[k][t] < m)
              {
                         g = a[k][t];
                         n = 1;
                         break;
              }
         }
         
       //  printf("%dll  ", t);
         if(n != 1)
         {
              if( m < l)
                       l=m;
              p=1;
         }
    }
    if(p = 1)
    {
         printf("\n\n\n%d\n", m);
    }
    else
        printf("GUESS\n");*/
        }
        getchar();
        getchar();
    return 0;
}
         
              
                       
    

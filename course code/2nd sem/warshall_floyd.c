#include <stdio.h>

int main()
{
    int i,j,n,k,x[100],l=0;
    int a[10][10],b[10][10];
    scanf("%d", &n);
    for (i= 0; i < n; i++)
    {
        for (j =0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if(i == j)
            {
                 b[i][j] = -1;
            }
            else
            {
                b[i][j] = i;
            }
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j =0; j < n; j++)
            { 
                if(a[i][k] + a[k][j] < a[i][j]) {
                           a[i][j] = a[i][k] + a[k][j];
                           b[i][j] = k;
                }
            }
        }
    }
    printf( "weight matrix :\n\n");
    for (i= 0; i < n; i++)
    {
        for (j =0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf( "\n");
    }
    printf( "path matrix :\n\n");
    for (i= 0; i < n; i++)
    {
        for (j =0; j < n; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf( "\n");
    }
    scanf("%d%d", &i, &j);
    k = j;
    while(1)
    {
                  x[l] = b[i][k];
                  k = b[i][k];
                  l++;
                  if (k == i)
                     break;
    } 
    
    for (i= l-1; i >= 0; i--)
         printf("%d ", x[i]);
    
    getchar();
    getchar();
    return 0;
}

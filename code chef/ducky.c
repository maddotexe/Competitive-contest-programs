#include <stdio.h>

int main()
{
    int t, a[5],i,k;
    char b[2000];
    scanf("%d", &t);
    getchar();
    while(t--)
    {
              for ( i =0 ; i < 5; i++)
                  a[i] =0;
              k=0;
         gets(b);
         while(b[k]== 'D' || b[k]== 'u' || b[k]== 'c'|| b[k]== 'k' || b[k]== 'y' || b[k]== '.')
         {
                      
                      if(b[k]== 'D')
                      a[0] = 1;
                      if(b[k]== 'u')
                      a[1] = 1;
                      if(b[k]== 'c')
                      a[2] = 1;
                      if(b[k]== 'k')
                      a[3] = 1;  
                      if(b[k]== 'y')
                      a[4] = 1; 
                      k++; 
         }
         if(a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1 && a[4] == 1)
         {
                 printf("DUCKY IS HERE!\n");
         }
         else
             printf("NO DUCKY!\n");
    }
    return 0;
}
    

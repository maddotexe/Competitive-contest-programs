#include <stdio.h>
int main()
{
         int t,n,c;
         scanf("%d", &t);
         while(t--)
         {
                   c = 0;
                   scanf("%d", &n);
                   if( n >= 2048)
                   {
                         c += n / 2048;
                         n = n % 2048;
                   }
                   if(n >= 1024)
                   {
                        c += n / 1024;
                         n = n % 1024;
                   }
                   if( n >= 512)
                   {
                       c += n / 512;
                         n = n % 512;
                   }
                   if(n >= 256)
                   {
                        c += n / 256;
                         n = n % 256;
                   }
                   if( n >= 128)
                   {
                       c += n / 128;
                         n = n % 128;
                   }
                   if( n >= 64)
                   {
                       c += n / 64;
                         n = n % 64;
                   }  
                   if( n >= 32)
                   {
                       c += n / 32;
                         n = n % 32;
                   }  if( n >= 16)
                   {
                       c += n / 16;
                         n = n % 16;
                   }  if( n >= 8)
                   {
                       c += n / 8;
                         n = n % 8;
                   }  if( n >= 4)
                   {
                       c += n / 4;
                         n = n % 4;
                   }  if( n >= 2)
                   {
                       c += n / 2;
                         n = n % 2;
                   }  
                   c += n;
                    printf("%d\n", c);
         }
         return 0;
}

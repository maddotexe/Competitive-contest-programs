#include <stdio.h>
#include <string.h>

int divi(char a[50002], int d)
{
    int i, n, r;
    i = 0;
    r = 0;
    while (a[i] != '\0') {
          r *= 10;
          r += a[i] - 48;
          r %= d;
          i++;
    }
    
    if (r)
       return 0;
    else 
         return 1;
}

int main()
{
    int u, t;
    char a[50005];
    scanf("%d", &t);
    while (t--) {
          scanf("%s", &a);
          u = divi(a, 252);
          if(u) 
                printf("Yes ");
          else 
                printf("No ");
          u = divi(a, 525);
          if(u) 
                printf("Yes\n");
          else 
               printf("No\n");
    }
    return 0;
}

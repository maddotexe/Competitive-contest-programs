#include <stdio.h>

#define n 1000000007

unsigned long long int fast (unsigned long long int a, unsigned long long int b) 
{
    unsigned long long int x;
    
    if (b == 0)
         return 1;
    if (b == 1)
         return a;
    x = fast(a, b/2);
    x *= x;
    x %= n;
    
    if (b & 1) { 
       x *= a;
       x %= n;
    }
       
    return x;
}

int main()
{
    unsigned long long int a, h, d;
    int i, t, c;
    scanf("%d", &t);
    while(t--) {
               d = 0;
               scanf("%d", &c);
               for (i = 0; i < c; i++) {
                      scanf("%lld", &h);
                      d += h;
                      d %= n;
               }
               h = fast(2, c - 1);
               h = d * h;
               h %= n;
               
               printf("%lld\n", h);
    }
    return 0;
}

#include <stdio.h>

unsigned long long int fast (unsigned long long int a, unsigned long long int b) 
{
    unsigned long long int x;
    
    if (b == 0)
         return 1;
    if (b == 1)
         return a;
    x = fast(a, b/2);
    x *= x;
    
    if (b & 1) 
       x *= a;
       
    return x;
}

int main()
{
    unsigned long long int n;
    scanf("%lld", &n);
    n = fast(2, n);
    printf("%lld", n);
    return 0;
}

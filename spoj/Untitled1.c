#include <stdio.h>
#include <math.h>
int main ()
{
    int n,a=0,j;
    scanf("%d", &n);
    for (j = 1; j <= ((int)sqrt(n)); j++)
        a += (n/j - j + 1);
    printf("%d", a);
    getchar();
    return 0;
}

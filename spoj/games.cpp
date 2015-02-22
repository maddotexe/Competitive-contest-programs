#include <stdio.h>

int main()
{
    int t;
    int n;
    float f, f1;
    
    scanf("%d", &t);
    
    while (t--) {
          scanf("%lf", &f);
          
          f1 = f - (int)f;
          
          printf("%lf\n", f1);
    }
    
    return 0;
}

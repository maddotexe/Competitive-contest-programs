#include <stdio.h>

//function calculator
float g(float x,float a,float b, float c)
{
     float y = a * x * x + b * x + c;
      return y;
}

int main()
{
    float a, b, c, x0, x1, x2, y0, y1, y2;
    //input
    scanf("%f%f%f%f%f", &a, &b, &c, &x0, &x1);
    
    //falsi operation
    while(((x0 - x1) > 0.001) || ((x1 - x0) > 0.001)) {              
    y0 = g(x0, a, b, c);
    y1 = g(x1, a, b, c);
    x2 = x0 - ((x0 - x1)/(y0 - y1))* y0;
    y2 = g(x2, a, b, c);
    
    if(y0 * y2 < 0) {
          printf("a1 root in %f %f\n", x0, x2);
          x1 = x2;
    }
    else {
         printf("a root in %f %f\n", x2, x1);
         x0 = x2;
    }
    }
    printf("%f\n", x0);

    getchar();
    getchar();
    return 0;
}
       

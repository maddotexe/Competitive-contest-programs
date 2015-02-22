#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,i,j;
    //enter the size
    cout << "Enter the size : ";
    cin >>n;
    double a[n][n],b[n],c[n],max;
    //enter the matrix
    for(i = 0; i < n; i++) {
          for(j = 0; j < n; j++) {
                cin >> a[i][j];
          }
          cin >> b[i]; 
          c[i] = 0;
    }
    int f = 0;
    double l;
    //calculating eigen value
    while(1) {
             
             f++;
             for(i = 0; i < n ;i++) {
                   c[i] = 0;
             }
             for(i = 0; i < n; i++) {
                      for(j = 0; j < n; j++) {
                              c[i] += a[i][j] * b[j];
                      }
             }
                  max = fabs(c[0]);
                  for(i = 0; i < n; i++) {
                        if(fabs(c[i]) > fabs(max))
                                max = fabs(c[i]);
                  }
                  for(i = 0; i < n; i++) {
                        c[i] /= max;
                        b[i] = c[i];
                  }
                        if((max > l ? max-l : l-max) < 0.00001)
                           break;
             l = max;
    }  
    //output
    cout << "Eigen value : " << max << "\nIteration : "<< f;
    getchar();
    getchar();
    return 0;
} 

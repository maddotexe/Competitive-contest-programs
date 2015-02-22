#include <iostream>
#include <math.h>
using namespace std;

int main()
{   int N;
    cin >> N;
    float a[N][N], c[N];
    float b[N];
    float I[N][N];
    
    int i, j, l, x, y;
    float k, d;
    d = 1.0;    
    
    for(i = 0; i < N; i++) {
          for(j = 0; j < N; j++) {
                cin >> a[i][j];
                if(i != j) {
                     I[i][j] = 0;
                }
                else {
                     I[i][j] = 1;
                }
          }
          cin >> b[i];
          c[i] = 0;
    }
    
    for(i = 0 ; i < N; i++) {
          for(j = 0; j < N; j++) {
                k = a[j][i];
                d = d * k;
                for(l = 0; l < N; l++) {
                      a[j][l] = a[j][l]/k;
                      I[j][l] = I[j][l]/k;
                }
                b[j] = b[j]/k;
          }
          
          for(j = 0; j < N; j++) {
                for(l = 0; l < N; l++) {
                      if(l != i) {
                           a[l][j] =  a[l][j] - a[i][j];
                           I[l][j] = I[l][j] - I[i][j];
                      }
                }
                if(j != i) {
                     b[j] = b[j] - b[i];
                }
          }      
          
    }
   
    for(i = 0; i < N; i++) {
          for(j = 0; j < N; j++) {
                I[i][j] = I[i][j] / a[i][i];     
          }
          b[i] = b[i] / a[i][i];
          d = d * a[i][i];
          a[i][i] = 1;
    }
    
    cout << endl << "\nInverse of the matrix --------->>>>>>>>>\n";
    
    for(i = 0; i < N; i++) {
          for(j = 0; j < N; j++) {
                cout << I[i][j] << " ";
          }
          cout << endl;
    }
    int f = 0;
    double l1, max;
    while(1) {
             
             f++;
             for(i = 0; i < N ;i++) {
                   c[i] = 0;
             }
             for(i = 0; i < N; i++) {
                      for(j = 0; j < N; j++) {
                              c[i] += I[i][j] * b[j];
                      }
             }
                  max = fabs(c[0]);
                  for(i = 0; i < N; i++) {
                        if(fabs(c[i]) > fabs(max))
                                max = fabs(c[i]);
                  }
                  for(i = 0; i < N; i++) {
                        c[i] /= max;
                        b[i] = c[i];
                  }
                        if((max > l1 ? max-l1 : l1-max) < 0.00001)
                           break;
             l1 = max;
    }  
    cout << "Eigen value : " << 1/max << "\nIteration : "<< f;
    getchar();
    getchar();
    getchar();
    return 0;
}

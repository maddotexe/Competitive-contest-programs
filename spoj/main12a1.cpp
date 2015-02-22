#include <cstdio>
#include <iostream>
#include <vector>
#define N 1000000
using namespace std;
int main()
{
    int i;
    int t;
    int t1;
    int n,j,k,d,b,y;
    vector <int> v;
    scanf("%d", &t1);

                     d = 2;
                     t = 3;
                     v.push_back(1);
                     v.push_back(2);
                     for( i = 2; d <= N ; i++) {          
                          for (k = 1; k < i; k++) {
                              for ( j = 1; j <= i; j++) {
                                  b = t;
                                  v.push_back(b);
                                  d++;
                                  cout << b << endl;
                              }
                              t++;
                          }
                     }
                     
                
  for(y = 1; y <= t1; y++){
                scanf("%d", &n);
                printf("Case #%d: %d\n",y,v[n-1]);
  }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    vector <int> v;
    vector <int>::iterator it;
    int i,q,x,k;
    scanf("%d", &t);
    while(t--) {
               scanf("%d", &q);
               while(q--) {
                      scanf("%d%d", &k, &x);
                      if( k == 1)
                          v.push_back(x);
                      else if( k == 2) {
                          it = find(v.begin(), v.end(), x);
                          it= v.erase(it);
                      }
                      else if( k == 3) {
                           printf("%d\n", v[x-1]);
                      }
                      else {
                           it = v.begin();
                           for( it, i = 0; it != v.end(); it++, i++) {
                                if(*it == x) {
                                       break;
                                }
                           }
                           printf("%d\n", i+1);
                      }
               }
               v.clear();
    }
    
    getchar();
    getchar();
    return 0;
}
                      

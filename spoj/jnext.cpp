#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> v;
    int t, n, i, x, j, pos;
    scanf("%d", &t);
    while (t--) {
                begin :
                scanf("%d", &n);
                for( i = 0; i < n; i++) {
                     scanf("%d", &x);
                     v.push_back(x);
                }
                for( i = n - 1; i > 0; i--) {
                    if(v[i] > v[i-1]) {
                            pos = i;
                            x = v[i];
                            for( j = n -1 ; j >= i; j--) {
                                 if(v[i-1] < v[j] ) {
                                         break;
                                 }
                            }
                            x = v[j];
                            v[j] = v[i-1];
                            v[i-1] = x;
                            goto z;
                    }
                }
                printf("-1\n");
                t--;
                v.clear();
                goto begin;
                z:
                sort(v.begin() + pos, v.end());
                for( i = 0; i < n; i++)
                     printf("%d", v[i]);
                     printf("\n");
                v.clear();
    }
    return 0;
}
                

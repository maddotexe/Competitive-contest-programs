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
                scanf("%d", &n);
                for( i = 0; i < n; i++) {
                     scanf("%d", &x);
                     v.push_back(x);
                }
                if(next_permutation(v.begin(), v.end())) {
                for( i = 0; i < n; i++)
                     printf("%d", v[i]);
                     printf("\n");
                }
                else {
                     printf("-1\n");
                }
                v.clear();
    }
    return 0;
}
                

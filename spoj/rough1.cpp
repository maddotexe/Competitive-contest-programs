#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> v;
    int n, i;
    int k,p,c=0,t;
    vector <int>::iterator it;
    scanf("%d", &t);
    while(t--) {
               scanf("%d%d", &n, &k);
               c= 0;
               for( i = 0; i < n; i++)
               {
                         scanf("%d", &p);
                         v.push_back(p);
               }
               for(it = v.begin(); it!=v.end(); it++)
               {
                       if(find(v.begin(), v.end(), k - (*it) ) != v.end())
                                    c++;
               }
               printf("%d\n",c/2);
               v.clear();
    }
    return 0;
}

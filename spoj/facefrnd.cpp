#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set <int> s;
    set <int> s1;
    set <int> s2;
    set <int>::iterator it;
    
    int i;
    int x;
    int n;
    int m;
    int j;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
          scanf("%d", &x);
          s.insert(x);
          scanf("%d", &m);
          for(j = 0; j< m; j++) {
                scanf("%d", &x);
                s1.insert(x);
          }
    }
 set_intersection(s.begin(), s.end(), s1.begin(), s1.end(), inserter(s2, s2.end()));
    cout << s1.size() - s2.size() << endl;
    return 0;
}


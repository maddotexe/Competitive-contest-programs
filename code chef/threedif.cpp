#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    unsigned long long int a[3], s;
    
    scanf("%d", &t);
    
    while (t--) {
          scanf("%lld%lld%lld", &a[0], &a[1], &a[2]);
          
          sort(a, a + 3);
          
          s = a[0] % 1000000007;
          
          s = (s * ((a[1] - 1) % 1000000007)) % 1000000007;
          
          s = (s * ((a[2] - 2) % 1000000007)) % 1000000007;
          
          cout << s << endl;
          
    }
    
    return 0;
}
          
          
          

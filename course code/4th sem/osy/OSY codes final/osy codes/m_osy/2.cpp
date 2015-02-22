#include <iostream>
#include <map>

using namespace std;

long long int bin(long long int n)
{
    int x = 0;
    while (n) {
        x += n & 1;
        n >>= 1;
    }
    
    return x;
}

int main()
{
    map<long long int,long long int> m;
    map<long long int, long long int>::iterator qt;
    long long int ans, n;
    
    cin >> n;
    
    while (n--) {
        cin >> ans;
        m[bin(ans)]++;
    }
    
    ans = 0;
    for (qt = m.begin(); qt != m.end(); qt++) {
        ans += (qt->second * (qt->second - 1)) / 2;
    }
    

    cout << ans << endl;
}

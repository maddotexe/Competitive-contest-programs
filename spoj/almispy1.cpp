#include <iostream>
#include <vector>
#include <cstdio>
 
using namespace std;
 
vector<vector<long long> > pow(vector<vector<long long> > tt, long long n, long long m)
{
    if(n == 1) {
        return tt;
    }
    if(!(n&1))
    {
        vector<vector<long long> > vv;
        vv = pow(tt, n/2, m);
        tt[0][0] = ((vv[0][0]*vv[0][0])%m + (vv[0][1]*vv[1][0])%m) % m ;
        tt[0][1] = ((vv[0][0]*vv[0][1])%m + (vv[0][1]*vv[1][1])%m) % m;
        tt[1][0] = ((vv[1][0]*vv[0][0])%m + (vv[1][1]*vv[1][0])%m) % m;
        tt[1][1] = ((vv[1][0]*vv[0][1])%m + (vv[1][1]*vv[1][1])%m) % m;
        return tt;
    }
    else {
        vector<vector<long long> > vv = pow(tt, n-1, m);
        tt[0][0] = ((vv[0][0]*0)%m + (vv[0][1]*1)%m) % m ;
        tt[0][1] = ((vv[0][0]*1)%m + (vv[0][1]*2)%m) % m;
        tt[1][0] = ((vv[1][0]*0)%m + (vv[1][1]*1)%m) % m;
        tt[1][1] = ((vv[1][0]*1)%m + (vv[1][1]*2)%m) % m;
        return tt;
    }
}
int main()
{
    int t;
 
    cin >> t;
 
    while(t--) {
        long long n, m;
        scanf("%lld%lld", &n, &m);
        if(n == 1) {
            cout << 3%m << " " << 5%m << endl;
            continue;
        }
        vector<vector<long long> > tt;
        vector<long long> v(2);
        v[0] = 0;
        v[1] = 1;
        tt.push_back(v);
        v[0] = 1;
        v[1] = 2;
        tt.push_back(v);
        tt = pow(tt, n-1, m);
        //cout << tt[0][0] << " " << tt[0][1] << endl << tt[1][1] << " " << tt[0][1] << endl;
        long long x = (tt[0][0]+(tt[0][1]*2)%m)%m;
        long long y = (tt[1][0]+(2*tt[1][1])%m)%m;
        //cout << x << " " << y << endl;
        long long c = (y*y)%m - (x*x)%m;
        c = c % m;
        long long d = (2*((x*y)%m))%m;
        long long e = ((x*x)%m + (y*y)%m)%m;
        if(c < 0) c += m;
        if(d < 0) d += m;
        if(e < 0) e += m;
        x = (n&1)?c:d;
        printf("%lld %lld\n", x, e);
    }
}
 

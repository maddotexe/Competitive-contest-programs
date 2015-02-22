#include <iostream>
#define mod 1000000007
 
using namespace std;
 
int main()
{
    int t;
 
    cin >> t;
 
    while(t--) {
        long long int n, k, gm, go;
        gm = 0;
        go = 1;
        cin >> n >> k;
        for(int i = 0; i < n-1; i++) {
            long long int b = gm;
            gm = (go*(k))%mod;
            go = (((go*(k-1)) % mod) + b)%mod;
        }
 
        cout << gm << endl;
    }
}

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int a[100010];
int b[100010];
int c[100010];

int main() {
    int t, n, m, p, q;
    
    cin >> t;
    
    while(t--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        cin >> n >> m;
        
        int k = 1;
        int g = n;
        int h = 0;
        while (m--) {
            cin >> p >> q;
            if (a[p] && a[q]) {
                if (c[a[p]] != c[a[q]]){
                    if (c[a[p]] < c[a[q]]) {
                        b[c[a[p]]] += b[c[a[q]]];
                        b[c[a[q]]] = 0;
                        c[a[q]] = c[a[p]];
                        h++;
                    } else if (c[a[p]] > c[a[q]]){
                        b[c[a[q]]] += b[c[a[p]]];
                        b[c[a[p]]] = 0;
                        c[a[p]] = c[a[q]];
                        h++;
                    }
                    //cout << p << " " << q << " " << b[a[q]] << " " << b[a[p]] << " " << c[a[p]] <<endl;    
                }
            } else if(a[p] == 0 && a[q] == 0) {
                a[p] = a[q] = k;
                b[k] += 2;
                c[k] = k;
                k++;
                g -=2;
            } else if(a[p] == 0 && a[q]) {
                a[p] = a[q];
                b[c[a[q]]]++;
                g--;
            } else if(a[q] == 0 && a[p]) {
                a[q] = a[p];
                b[c[a[q]]]++;
                g--;
            } 
            
        }
        cout << k - h + g - 1 << " ";
        long long int sum = 1;
        for (int i = 1; i < k; i++) {
            if (b[i]) {
                //cout << i << " " << b[i] <<endl;
                sum = ((sum % 1000000007) * b[i] % 1000000007) % 1000000007;
            }
        }
        cout << sum << endl;
    }
    return 0;
}

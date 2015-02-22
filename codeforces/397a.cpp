#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <climits>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ll long long
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))

int abs(int x) {if(x < 0) return -x; return x;}

int aa[100005], l[100005], r[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < n-1; i++) {
        cin >> l[i] >> r[i];
        for(int j = l[i]+1; j < r[i]; j++) {
            aa[j]++;
        }
    }
    for (int i=  0; i < n; i++) {
    	//cout << l[i] << r[i];
    }
    int ans = 0;
    for(int i = a; i <= b; i++) {
        int pos = i;
        if(aa[i]) continue;
        while(!aa[pos] && pos <= b) pos++;
        ans += (pos-i-1);
        i = pos-1;
    }
    cout << ans << endl;
}

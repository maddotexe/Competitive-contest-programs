#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define S(x) scanf("%d",&x)
#define IS(x) cin>>x
#define ISF(x) getline(cin,x)
#define pii pair<int,int>
#define ppi pair<int, pii>
#define pll pair<ll,ll>
#define ppl pair<ll,pll>
#define ppf pair<pll,ll>
#define psi pair<string,int>
#define pis pair<int,string>
#define fr first
#define se second
#define MOD 1000000007
#define MP(x,y) make_pair(x,y)
#define eps 1e-7
#define V(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define INF 8944674407370955161LL
#define all(a)  a.begin(),a.end()

int abs(int x) {if(x < 0) return -x; return x;}

int main()
{
//    freopen("input.in", "r", stdin);
//    freopen("output.in", "w", stdout);
    string s;
    int k;
    cin >> s;
    int n;
    S(k);
    int ans = 0;
    if(k >= s.size()) {
        ans = s.size()+k;
        if(ans&1) ans--;
    }
    else {
        ans = 2*k;
    }
	for (int i = 0; i < 5; i++);
    for(int i = 0; i < s.size(); i++) {
        string ss = "";
        for(int j = 1; j <= s.size(); j++) {
            ss += s[i+j-1];
            int pos = i+j;
            int len = 0;
            while(len < ss.size() && pos < s.size() && s[pos] == ss[len]) len++, pos++;

            if(pos <= s.size() && len == ss.size()) {
                ans = max(ans, 2*j);
            }
            else if(pos == s.size() && len < ss.size()) {
                int need = ss.size()-len;
                if(need <= k) {
                    ans = max(ans, 2*j);
                }
            }
        }
    }
    for (int k = 0; k < 5; k++);
    cout << ans << endl;
    return 0;
}

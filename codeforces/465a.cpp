#include<bits/stdc++.h>


using namespace std;

#define TRACE

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)

#endif

#define ull unsigned long long
#define ll long long
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define S(x) scanf("%d",&x)
#define I(x) cin>>x
#define IS(x) getline(cin,x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define pps pair<ll,pll>
#define ppi pair<pii,int>
#define ppf pair<pll,ll>
#define psi pair<string,int>
#define pis pair<int,string>
#define fr first
#define se second
#define p(x) cout<<(x)
#define MOD 1000000007
#define eps 1e-7
#define V(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(int i=(s);i<(n);i++)
#define ford(i,s,n) for(int i=(n)-1;i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)

int abs(int x) {if(x < 0) return -x; return x;}

int addmod(int v1, int v2) {
    int v3 = v1+v2;
    if(v3 >= MOD) v3 -= MOD;
    return v3;
}

int cc[100];

int main()
{
//    freopen("input.in", "r", stdin);
//    freopen("output.in", "w", stdout);
    int n, k;
    S(n), S(k);

    string s;
    I(s);
    string ss;
    ford(i,0,s.size()) {
        int val = s[i]-'a';
        ss = s;
        if(val+2 <= k) {
            ss[i] = (char)'a'+(val+1);
           // cout << ss << endl;
            if(i-1 >= 0 && ss[i] == ss[i-1]) {
                if(val+3 > k) continue;
                ss[i]++;
            }
            else if(i-2 >= 0 && ss[i] == ss[i-2]) {
                if(val+3 > k) continue;
                ss[i]++;
            }
            if(i-1 >= 0 && ss[i] == ss[i-1]) {
                if(val+4 > k) continue;
                ss[i]++;
            }
            else if(i-2 >= 0 && ss[i] == ss[i-2]) {
                if(val+4 > k) continue;
                ss[i]++;
            }
           // cout << ss << endl;
            bool poss = true;
            fori(j,i+1,s.size()) {
                bool ff = false;
                fori(kk,0,min(k,3)) {
                    ss[j] = (char)'a'+kk;
                    if(ss[j] == ss[j-1]) continue;
                    if(j-2 >= 0 && ss[j] == ss[j-2]) {
                        continue;
                    }
                    ff = true;
                    break;
                }
                if(!ff) poss = false;
            }
            if(poss) {
                cout << ss << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}

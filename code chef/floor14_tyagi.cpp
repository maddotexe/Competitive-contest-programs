#include<bits/stdc++.h>
 
// Isme kya hai ;)
 
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
 
int b1[200005], b2[200005], x[200005], y[200005], pp[200005];
int n;
V(int) small[200006], larger[200006], pos[200006];
 
int get1(int pos)
{
    int sum = 0;
    while(pos > 0) {
        sum += b1[pos];
        pos -= pos&-pos;
    }
    return sum;
}
 
 
void update1(int pos, int val)
{
    while(pos < 200004) {
        b1[pos] += val;
        pos += pos&-pos;
    }
}
 
 int get2(int pos)
{
    int sum = 0;
    while(pos > 0) {
        sum += b2[pos];
        pos -= pos&-pos;
    }
    return sum;
}
 
 
void update2(int pos, int val)
{
    while(pos < 200004) {
        b2[pos] += val;
        pos += pos&-pos;
    }
}

 
int main()
{
   //freopen("input.in", "r", stdin);
   //freopen("output.in", "w", stdout);
    int n, m;
    S(n), S(m);
 // n = 2*100000;
//  m = n;
    int a[n];
    int b[n];
    fori(i,0,n) {
       S(a[i]);
        b[i] = a[i];
    }
    sort(b, b+n);
    mii mm;
    int c = 1;
 
    fori(i,0,n) {
        if(!mm[b[i]]) mm[b[i]] = c++;
    }
 
    fori(i,0,n) {
        pos[i].pb(mm[a[i]]);
        a[i] = mm[a[i]];
    }
 
    mm.clear();
 
    fori(i,0,m) {
        S(x[i]), S(y[i]);
       //x[i] = rand()%n + 1;
       //y[i] = rand()%n + 1;
       	//x[i] = n/3;
       //	y[i] = 2*n/3;
        x[i]--;
        y[i]--;
        pos[x[i]].pb(a[y[i]]);
        pos[y[i]].pb(a[x[i]]);
    }
 
    ll inv = 0;
    set<int> :: iterator it;
    fori(i,0,n) {
        fori(j,0,pos[i].size()) {
        //	cout << pos[i][j] << endl;
        	int oo = get1(pos[i][j]);
            small[i].pb(oo);
           // trace1(oo);
            larger[i].pb(get2(pos[i][j]));
            //trace2(small[i].back(), larger[i].back());
        }
        mm[a[i]]++;
        inv += larger[i][0];
        update1(a[i]+1,1);
        update2(1, 1);
        update2(a[i],-1);
        //trace2(b1[i], a[i]);
    }
    
    fori(i,0,n) {
    pp[i] = 1;
    //cout <<b1[i] << endl;
	}
    fori(i,0,m) {
    	int v1, v2;
    	if(a[x[i]] == a[y[i]]) {
    		p(inv), p(endl);
    		pp[x[i]]++;
    		pp[y[i]]++;
    		continue;
    	}
    	int p1, p2;
    	p1 = pp[x[i]];
    	p2 = pp[y[i]];
    	pp[x[i]]++;
    	pp[y[i]]++;
    	v1 = -larger[x[i]][0] + larger[y[i]][p2];
    	v2 = -larger[y[i]][0] + larger[x[i]][p1];
    	v1 += small[y[i]][0] - small[x[i]][p1];
    	v2 -= small[y[i]][p2] - small[x[i]][0];
    	printf("%lld\n",inv+v1+v2);
    }
   /* fori(i,0,m) {
        int v1, v2;
        if(a[x[i]] == a[y[i]]) {
       //     p(inv), p(endl);
            continue;
        }
        v1 = -larger[pii(x[i],a[x[i]])] + larger[pii(y[i],a[x[i]])];
        v2 = -larger[pii(y[i],a[y[i]])] + larger[pii(x[i],a[y[i]])];
        v1 += small[pii(y[i],a[y[i]])]-small[pii(x[i],a[y[i]])];
        v2 -= small[pii(y[i],a[x[i]])]-small[pii(x[i],a[x[i]])];
    //    printf("%lld\n", inv+v1+v2);
    } */
 
    return 0;
}

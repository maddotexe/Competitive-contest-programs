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

string s[10], ss[10001];
set <int> v, light, ansv;
bool check(int x, int y)
{
	bool f = true;
	trace2(x, y);
	for (int i = 0; i < ss[x].size(); i++) {
			
			if (ss[x][i] == '1' && s[y][i] == '1') {
				continue;
			} else if (ss[x][i] == '0' && s[y][i] == '0') {
				continue;
			} else if (ss[x][i] == '0' && s[y][i] == '1' && light.find(i) == light.end()) {
			//	cout << i << endl;
			        //trace1(i)
				v.insert(i);
				continue;
			} else {	
				f = false;
				break;
			}
	}
	
	return f;
}
int main()
{
//	ios_base::sync_with_stdio(false);
	//freopen("in3.in", "r", stdin);
	//freopen("out3.out", "w", stdout);
	
	int t, n;
	
	cin >> t;
	
	s[9] = "1111110";
	s[8] = "0110000";
	s[7] = "1101101";
	s[6] = "1111001";
	s[5] = "0110011";
	s[4] = "1011011";
	s[3] = "1011111";
	s[2] = "1110000";
	s[1] = "1111111";
	s[0] = "1111011";
	
	
	for (int cs = 1; cs <= t; cs++) {
		cout << "Case #" << cs << ": ";
		cin >> n;
		light.clear();
		ansv.clear();
		for (int i = 0; i < n; i++) {
			cin >> ss[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 7; j++) {
				if (ss[i][j] == '1') light.insert(j);
			}
		}
		vector <int> vv;
		vv.clear();
		//cout << light.size() << endl;
		bool f = true;
		int ans = -1;
		for (int j = 0; j < 10; j++) {
			f = true;
			v.clear();
			for (int i = 0, k = j; i < n; i++, k++) {
				if (!check(i, k % 10)) {
					f = false;
					break;
				}
				ans = k % 10;
			}
			if (f) {
				
				//cout << ans << endl;
				ansv = v;
				vv.pb(ans);
			}
		}
		
		if (vv.size() != 1) {
			//for (int i = 0; i < vv.size(); i++) cout << vv[i] << endl;
			cout << "ERROR!"<< endl;
		} else {
			ans = vv[0];
			//cout << ans << endl;
			string y = s[(10 + ans + 1) % 10 ];
			//cout << y << endl;
			for (set<int>::iterator it = ansv.begin(); it != ansv.end(); it++) {
				//cout << *it << endl;
				y[*it] = '0';
			}
			cout << y << endl;
		}
	}
	return 0;
}



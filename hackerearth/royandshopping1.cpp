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
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)
#define INF 8944674407370955161LL
#define all(a)  a.begin(),a.end()

int abs(int x) {if(x < 0) return -x; return x;}
char a[10];
int ans = 0;
struct node {
	node *next[26];
	bool flag[26];
};

node *init()
{
	node *head = new node;
	for (int i = 0; i < 26; i++) {
		(head)->next[i] = NULL;
		(head)->flag[i] = false;
	}
	return head;
}

void insrt(node *start) {
	int n = strlen(a);
	
	for (int i = 0; i < n; i++) {
		int ind = a[i] - 'a';
		if (!start->next[ind]) {
			start->next[ind] = init();
		}
		if (i == n - 1) {
			if (start->flag[ind] == false) ans++;
			start->flag[ind] = true;
		}
		start = start->next[ind];
		
	}
}

void print(node *start, char s[10], int k)
{
	if (start == NULL) return;
	char z;
	for (int i = 0; i < 26; i++) {
		z = 'a' + i;
		if (start->flag[i]) {
			for (int i = 0; i < k; i++) printf("%c", s[i]);
			printf("%c\n", z);
		}
		s[k] = z;
		print(start->next[i], s, k + 1);
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	getchar();
	node *start = NULL;
	start = init();
	
	for (int i = 0; i < n; i++) {
		scanf("%s", a);
		insrt(start);
	}
	cout << ans << endl;
	print(start, a, 0);
	return 0;
}



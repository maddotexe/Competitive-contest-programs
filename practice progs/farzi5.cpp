#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#define X first
#define Y second
#define pb push_back
#define fr(i,n) for(int i=1;i<=n;i++)
 
using namespace std;
 
typedef long long ll;
 
const int mod=(int)1e9+7;
 
int n,m;
int trie[2501000][63],cnt;
int v[2501000],fail[2501000];
int lk[300],b[510];
int q[2501000];
int indeg[2501000];
char str[501000];
 
void insert(int x)
{
	int idx=0;
	for(int i=1;str[i];i++)
	{
		if(!trie[idx][lk[str[i]]])
			trie[idx][lk[str[i]]]=++cnt;
		idx=trie[idx][lk[str[i]]];
	}
	b[x]=idx;
}
 
void build()
{
	int h=1,t=1;
	for(int i=0;i<63;i++)
		if(trie[0][i])
			q[t++]=trie[0][i];
	while(h<t)
	{
		int sta=q[h++];
		for(int i=0;i<63;i++)
			if(trie[sta][i])
			{
				fail[trie[sta][i]]=trie[fail[sta]][i];
				q[t++]=trie[sta][i];
			}
			else trie[sta][i]=trie[fail[sta]][i];
	}
}
 
void solve()
{
	int idx=0;
	for(int i=1;str[i];i++)
	{
		idx=trie[idx][lk[str[i]]];
		v[idx]++;
	}
}
 
void push()
{
	int h=1,t=1;
	for(int i=0;i<=cnt;i++)
		indeg[fail[i]]++;
	for(int i=0;i<=cnt;i++)
		if(!indeg[i])
			q[t++]=i;
	while(h<t)
	{
		int sta=q[h++];
		v[fail[sta]]+=v[sta];
		indeg[fail[sta]]--;
		if(!indeg[fail[sta]])
			q[t++]=fail[sta];
	}
}
 
int main()
{
	for(int i='a';i<='z';i++) lk[i]=i-'a';
	for(int i='A';i<='Z';i++) lk[i]=i-'A'+26;
	for(int i='0';i<='9';i++) lk[i]=i-'0'+52;
	lk['-']=62;
	int t;
	cin >> t;
	while (t--) {
		scanf("%s",str+1);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str+1);
			insert(i);
		}
		build();
		solve();
		push();
		for(int i=1;i<=n;i++)
			printf("%d\n",v[b[i]]);
	}
	return 0;
}

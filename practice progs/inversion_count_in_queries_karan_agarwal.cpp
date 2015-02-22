#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) FORi(i,(__typeof(n))0,n)
#define FOR(i,a,b) for(i=a ; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
using namespace std;
 
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef pair< PII , int > PIII;
 
int n;
int N;
bool foo(PIII a, PIII b)
{
   if( (a.F.F)/N != (b.F.F/N)   ) 
       return (a.F.F < b.F.F);
   return (a.F.S  < b.F.S);
}
 
PIII Q[20005];
int A[20005];
LL ans[20005];
LL BIT[20005];
 
set<int> S;map<int,int> M;
 
void update(int ind, int x)
{
    while(ind <= n) 
    {
        BIT[ind] += x;
        ind  += (ind & -ind);
    }
}
 
 
int query(int ind)
{
    int ret=0;
    while(ind)
    {
        ret += BIT[ind];
        ind = ind & (ind-1);
    }
    return ret;
}
 
 
int main()
{
    si(n); N = sqrt(n);
    repi(i,n) 
    {
        si(A[i+1]); 
        S.insert(A[i+1]);
    }
    int c = 0;TR(S,i) M[*i] = ++c;
    repi(i,n) A[i+1] = M[A[i+1]];
//    repi(i,n) cout<<A[i+1]<<" "; cout<<endl;
    int q; si(q);
    repi(i,q)
    {
        si(Q[i].F.F); 
        si(Q[i].F.S);
        Q[i].S=i;
    }
//    repi(i,q) cout<<Q[i].F.F<<" "<<Q[i].F.S<<endl;
    sort(Q,Q+q,foo);
//    repi(i,q) cout<<Q[i].F.F<<" "<<Q[i].F.S<<endl;
    int l=1,r=1;
    LL curr=0;
    update(A[1],1);
    repi(i,q)
    {
        while(r<Q[i].F.S)
        {
            r++; update(A[r],1);
            curr += query(n) - query(A[r]);
        }
        while(r>Q[i].F.S)
        {
            update(A[r],-1);
            curr -= query(n) - query(A[r]);
            r--;
        }
        while(l>Q[i].F.F)
        {
            l--; update(A[l],1);
            curr += query(A[l]-1);
        }
 
        while(l<Q[i].F.F)
        {
            update(A[l],-1);
            curr -= query(A[l]-1);
            l++;
        }
//        cout<<i<<" done\n";
        ans[Q[i].S] = curr;
    }
    repi(i,q) cout<<ans[i]<<endl;
    return 0;
}
 

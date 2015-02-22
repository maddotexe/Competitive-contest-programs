// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel is now in high school.
The seats in her classroom are arranged into an n by m matrix.
The rows are numbered from 0 to n-1 (front to back) and the columns from 0 to m-1 (left to right).



At the beginning, Ciel can choose any of the seats.
Then, at the end of each week Ciel will shift one row to the back and one column to the right, wrapping around whenever necessary.
Formally, if her current seat is in row r and column c, then her seat next week will be the one in row ((r+1) modulo n) and column ((c+1) modulo m).



Fox Ciel now wonders whether she can sit in all the seats in the classroom if she follows the above procedure.
As we already mentioned, she can start in any of the seats.
Also, she can attend the school for as many weeks as she wants to.
Return "Possible" if she can sit in all the seats and "Impossible" otherwise.

DEFINITION
Class:FoxAndClassroom
Method:ableTo
Parameters:int, int
Returns:string
Method signature:string ableTo(int n, int m)


CONSTRAINTS
-n will be between 2 and 10, inclusive.
-m will be between 2 and 10, inclusive.


EXAMPLES

0)
2
3

Returns: "Possible"

We will use (r,c) to denote the chair at row r, column c.
Suppose Ciel starts at (1,0).
In the following weeks she will then sit at (0,1), (1,2), (0,0), (1,1), (0,2), (1,0) again, (0,1) again, and so on.
We can see that already after 6 weeks Ciel sat in all the seats.

1)
2
2

Returns: "Impossible"

Suppose that she starts at (0,0).
Then the next week she will sit at (1,1) and the week after that she will be back at (0,0).
She would never sit at (0,1) and (1,0).
Similarly we can show that none of the other starting positions work.

2)
4
6

Returns: "Impossible"



3)
3
6

Returns: "Impossible"



4)
5
7

Returns: "Possible"



5)
10
10

Returns: "Impossible"



// END CUT HERE
#line 91 "FoxAndClassroom.cpp"
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <numeric>
#include <cstring>

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
#define pll pair<ll,ll>
#define pps pair<ll,pll>
#define ppf pair<pll,ll>
#define psi pair<string,int>
#define pis pair<int,string>
#define fr first
#define se second
#define ln length()
#define MP(x,y) make_pair(x,y)
#define eps 1e-7
#define vi(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
#define MOD 1000000007
#define INF 8944674407370955161LL

class FoxAndClassroom {
	public:
	string ableTo(int n, int m) {
		bool a[n][m];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x = i, y = j;
				memset(a, 0, sizeof(a));
				sum = 0;
				while (1) {
					if (a[x][y] == false) {
						a[x][y] = true;
						sum++;
						if (sum == n * m) {
							return "Possible";
						}
						x = (x + 1) % n;
						y = (y + 1) % m;
					} else {
						break;
					}
				}
			}
		}
		return "Impossible";
	}
};

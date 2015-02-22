// BEGIN CUT HERE
// PROBLEM STATEMENT
// The first thing you have to do is to concatenate all elements of actions into one long string, and that will be your input string.
In this problem, you will write a program that controls the actions of a progress indicator. The indicator is a single bar character in the middle of the screen with one of 4 states: '|', '/', '-', and '\'. From now on, we will refer to '\' as 'N', for programming convenience. The program is a sequence of instructions in the form:
<instr> <secs>
where <instr> represents one of 4 possible actions, and <secs> is the action's duration in seconds. The action is performed once each second. The 4 possible actions are:
'L': Spin left.  If the bar is in state '|', it goes to 'N'.  State 'N' goes to '-', '-' goes to '/', and '/' goes to '|'.
'R': Spin right.  This is the exact opposite of 'L': 'N' goes to '|', '|' goes to '/', '/' goes to '-', and '-' goes to 'N'.
'S': Stay.  The bar remains in its current state.
'F': Flip.  The bar is rotated 90 degrees: '|' becomes '-', '-' becomes '|', '/' becomes 'N', and 'N' becomes '/'.
So, the sequence "F03L02" and the starting state of '-' leads to the following sequence: "-|-|N-".
Given a vector <string> actions representing a sequence of actions, return the shortest program that leads to that sequence. The first character of the sequence is the starting state, so your program should run for K-1 seconds where K is the length of the given sequence. If there are multiple shortest programs that produce the given sequence, return the lexicographically first among them. If the return string has more than 100 characters, return only the first 97 followed by "..." (see last example for clarification).

DEFINITION
Class:IndicatorMotionReverse
Method:getMinProgram
Parameters:vector <string>
Returns:string
Method signature:string getMinProgram(vector <string> actions)


NOTES
-You can't make an action last more than 99 seconds with a single instruction, but you can use the same instruction multiple times consecutively (see example 2 for further clarification).
-If two programs have the same size, the one that comes earlier lexicographically is the one with the lower ASCII value in the first position at which they differ.


CONSTRAINTS
-actions will have between 1 and 50 elements, inclusive.
-Each element in actions will have between 1 and 50 characters, inclusive.
-Each character of each element of actions will be one of '|', 'N', '-' or '/'.


EXAMPLES

0)
{"-|-|/-/|//////-/"}

Returns: "F03R02L02R01S05R01L01"

The actions needed after the first '-', which is the starting state, are:

-|-|/-/|//////-/
.FFFRRLLRSSSSSRL

which can be optimally represented using the syntax above.

1)
{"N"}

Returns: ""

Sometimes you need an empty program.

2)
{"||||||||||||||||||||||||||||||||||||||||||||||||||",
 "||||||||||||||||||||||||||||||||||||||||||||||||||",
 "||||||||||||||||||||||||||||||||||||||||||||||||||"}

Returns: "S50S99"

Here you need 149 stays and it is necessary to break them into 2 'S' instructions. The lexicographically first way to do this is S50S99.

3)
{"N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N"}

Returns: "L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L..."

In this case the output program has 400 instructions, which is 3x400=1200 characters. Remember to return only the first 97 followed by "...".

// END CUT HERE
#line 80 "IndicatorMotionReverse.cpp"
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
#define ff first
#define ss second
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

int abs(int x) {if(x < 0) return -x; return x;}

string func(int n) 
{
	string s ="";
	while (n != 0) {
		s += (char)(n % 10 + '0');
		n /= 10;
	}
	if (s.size() == 1) s = '0' + s;
	return s;
}

class IndicatorMotionReverse {
	public:
	
	string getMinProgram(vector <string> v) {
		string s = "";
		map<char, int> m;
		m['-'] = 1;
		m['N'] = 2;
		m['|'] = 3;
		m['/'] = 4;
		
		string s2 = "SRFL";
		string res = "";
		int j;
		for (int i = 0; i < v.size(); i++) {
			s += v[i];
		}
		if (s.size() == 1) return "";
		
		for (int i = 0; i < s.size(); i++) {
			int count= 0;
			int diff = (m[s[i]] - m[s[i+1]]) + 4 % 4;
			j = i;
			while (j < s.size() - 1 && ((m[s[j]] - m[s[j+1]]) + 4 % 4) == diff) {
				j++;
				count++;
			}
			if (j != s.size() - 1) 
				i = j - 1;
			if (count > 99) {
				int f = count - 99;
				cout << s[diff] << endl;
				res += s[diff] + func(f) + s[diff] + func(99);
			} else {
				res += s[diff] + func(count);
			}
		}
		return res;
	}
};

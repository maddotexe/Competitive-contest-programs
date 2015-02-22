#include <iostream>
#include <vector>

using namespace std;

int cc = 1;
int n, m;
int tree[5000005];
int low[500005], high[500005];
vector<int> v[500005];
int vis[500005];
int a[500005];
int val[500005];

vector<int> ss;
void dfs(int pos)
{
	ss.push_back(pos);
	low[pos] = ss.size();	
	vis[pos] = 1;
	for(int i = 0; i < v[pos].size(); i++) {
		if(!vis[v[pos][i]]) {
			val[v[pos][i]+1] = ss.size();
			dfs(v[pos][i]);
		}
	}
	high[pos] = ss.size()-1;
}

int get(int pos)
{
	int sum = 0;
	while(pos > 0) {
		sum += tree[pos];
		pos -= (pos&-pos);
	}
	return sum;
}

void update(int pos, int val)
{
	while(pos <= n) {
		tree[pos] += val;
		pos += (pos&-pos);
	}
}

int main()
{
	cin >> n >> m;
	int x, y;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i < n-1; i++) {
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	val[1] = 0;
	dfs(0);
	for(int i = 0; i < m; i++) {
		int q;
		
		cin >> q;
		
		if(q == 1) {
			int x, y;
			
			cin >> x >> y;
			x--;
			a[x] += y;
			if(low[x] >= high[x]) continue;
			update(low[x], -y);
			update(high[x]+1, y);
		}
		else {
			int x;
			
			cin >> x;
			x--;
			cout << a[x] + get(val[x+1]) << endl;
		}
		for(int i = 0; i < n; i++) {
			cout << a[i] + get(val[i+1])<< " ";
		}
		cout << endl;
	}
}

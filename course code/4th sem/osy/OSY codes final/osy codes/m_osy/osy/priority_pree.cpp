#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct node {
	int i;
	int p_t;
};

bool operator<(node n1, node n2)
{
	if (n1.p_t <= n2.p_t) {
		return true;
	}
	return false;
}

void add(priority_queue<node> &pq, int t_prev, int t_now, vector<vector<int> > m, vector<bool> &c)
{
	for (int i = 1; i < m.size(); i ++)  {
		if (m[i][0] >= 0 && m[i][0] <= t_now && c[i] == 0) {
			node n;
			n.i = i;
			n.p_t = m[i][2];
			pq.push(n);
			c[i] = 1;
		}
	}
}

void print(priority_queue<node> p)
{
	while(!p.empty()) {
		cout << p.top().i << " ";
		p.pop();
	}
	cout << endl;
}

int main()
{
	int min_arrival_index, x, n, y;
	int t_prev, t_now;
	vector<bool> c;
	vector<vector<int> > v;
	vector<int> c_t, b_t;
	priority_queue<node> pq;
	struct node p;

	cout << "enter the number of processes\n";
	cin >> n;
	v.resize(n+1);
	c.resize(n+1);
	c_t.resize(n+1);
	b_t.resize(n+1);
	x = y = INT_MAX ;
	for (int i = 1; i<= n; i++) {
		v[i].resize(3);
		cout << "enter arr, bt\t";
		cin >> v[i][0] >> v[i][1] >> v[i][2];
		b_t[i] = v[i][1];
		if (x >= v[i][0]) {
			x = v[i][0];
			if (y >= v[i][2]) {
				y = v[i][2];
				min_arrival_index = i;
			}
		}
		c[i] = 0;
	}

	//the process which came first and have min bust time would be executed
	t_prev = 0;
	t_now = v[min_arrival_index][0];
	cout << "t_now = " << t_now << endl;
	add(pq, t_prev, t_now, v, c);

	while (!pq.empty()) {
		//cout << "size = " << pq.size();
		cout << "t now => " << t_now << "  ->>>>> ";
		print(pq);
		p = pq.top();
		min_arrival_index = p.i;
		c[min_arrival_index] = 0;
		cout << "\tindex = " << min_arrival_index << " timee = " << v[min_arrival_index][1] - 1 << endl;;
		pq.pop();
		t_prev = t_now;
		t_now = t_prev + 1;
		v[min_arrival_index][1]--;
		if (v[min_arrival_index][1] == 0) {
			c[min_arrival_index] = 1;
		}
		//cout << "\tt_now = " << t_now << endl;
		c_t[min_arrival_index] = t_now;
		add(pq, t_prev, t_now, v, c);
	}

	for (int i = 1; i<= n; i++) {
		cout << v[i][0] << "\t" << b_t[i] << " \t"  << v[i][2] << "\t" << c_t[i] << endl;
	}
	return 0;
}

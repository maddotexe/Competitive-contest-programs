#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct node {
	int i;
	int b_t;
};

bool operator<(node n1, node n2)
{
	if (n1.b_t > n2.b_t) {
		return true;
	}
	return false;
}

void add(priority_queue<node> &pq, int t_prev, int t_now, vector<vector<int> > m, vector<bool> &c)
{
	for (int i = 1; i < m.size(); i ++)  {
		if (m[i][0] >= t_prev && m[i][0] <= t_now && c[i] == 0) {
			node n;
			n.i = i;
			n.b_t = m[i][1];
			pq.push(n);
			c[i] = 1;
		}
	}
}

int main()
{
	int min_arrival_index, x, n, y;
	int t_prev, t_now;
	vector<bool> c;
	vector<vector<int> > v;
	vector<int> c_t;
	priority_queue<node> pq;
	struct node p;

	cout << "enter the number of processes\n";
	cin >> n;
	v.resize(n+1);
	c.resize(n+1);
	c_t.resize(n+1);
	x = y = INT_MAX ;
	for (int i = 1; i<= n; i++) {
		v[i].resize(2);
		cout << "enter arr, bt\t";
		cin >> v[i][0] >> v[i][1];
		if (x >= v[i][0]) {
			x = v[i][0];
			if (y >= v[i][1]) {
				y = v[i][1];
				min_arrival_index = i;
			}
		}
		c[i] = 0;
	}

	//the process which came first and have min bust time would be executed
	t_prev = 0;
	t_now = v[min_arrival_index][0];
	cout << " mi = " << min_arrival_index << endl;
	add(pq, t_prev, t_now, v, c);
	while (!pq.empty()) {
		cout << "size = " << pq.size() << endl;
		p = pq.top();
		min_arrival_index = p.i;
		cout << "index = " << min_arrival_index << endl;
		pq.pop();
		t_prev = t_now;
		t_now = t_prev + v[min_arrival_index][1];
		cout << "t_now = " << t_now << endl;
		c_t[min_arrival_index] = t_now;
		add(pq, t_prev, t_now, v, c);
	}
	for (int i = 1; i<= n; i++) {
		cout << v[i][0] << "\t" << v[i][1] << " \t" << c_t[i] << endl;
	}
    cin >> t_prev;
	return 0;
}

#include <iostream>
#include <queue>
#include <map>
#include <climits>

using namespace std;

struct node3 {
	int i;
	int p_t;
};

struct node {
	int i;
	int b_t;
};
struct node1 {
	int i;
	int b_t;
};
struct node2 {
	int i;
	int p_t;
};
bool operator<(node3 n1, node3 n2)
{
	if (n1.p_t <= n2.p_t) {
		return true;
	}
	return false;
}
void add3(priority_queue<node3> &pq, int t_prev, int t_now, vector<vector<int> > m, vector<bool> &c)
{
	for (int i = 1; i < m.size(); i ++)  {
		if (m[i][0] >= 0 && m[i][0] <= t_now && c[i] == 0) {
			node3 n;
			n.i = i;
			n.p_t = m[i][2];
			pq.push(n);
			c[i] = 1;
		}
	}
}

void print(priority_queue<node3> p)
{
	while(!p.empty()) {
		cout << p.top().i << " ";
		p.pop();
	}
	cout << endl;
}
bool operator<(node2 n1, node2 n2)
{
	if (n1.p_t < n2.p_t) {
		return true;
	}
	return false;
}
bool operator<(node1 n1, node1 n2)
{
	if (n1.b_t > n2.b_t) {
		return true;
	} else if(n1.b_t == n2.b_t) {
		return false;
	}
	return false;
}
void add2(priority_queue<node2> &pq, int t_prev, int t_now, vector<vector<int> > m, vector<bool> &c)
{
	for (int i = 1; i < m.size(); i ++)  {
		if (m[i][0] >= t_prev && m[i][0] <= t_now && c[i] == 0) {
			node2 n;
			n.i = i;
			n.p_t = m[i][2];
			pq.push(n);
			c[i] = 1;
		}
	}
}

void add(priority_queue<node1> &pq, int t_prev, int t_now, vector<vector<int> > m, vector<bool> &c)
{
	for (int i = 1; i < m.size(); i ++)  {
		if (m[i][0] >= 0 && m[i][0] <= t_now && c[i] == 0) {
			node1 n;
			n.i = i;
			n.b_t = m[i][1];
			pq.push(n);
			c[i] = 1;
		}
	}
}

void print(priority_queue<node1> p)
{
	while(!p.empty()) {
		cout << p.top().i << " ";
		p.pop();
	}
	cout << endl;
}

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
void add4(queue<int> &pq, int t_prev, int t_now, vector<vector<int> > m, vector<bool> &c)
{
	for (int i = 1; i < m.size(); i ++)  {
		if (m[i][0] >= 0 && m[i][0] <= t_now && c[i] == 0) {
			pq.push(i);
			c[i] = 1;
		}
	}
}
void print4(queue<int> p)
{
	while(!p.empty()) {
		cout << p.front() << " ";
		p.pop();
	}
	cout << endl;
}

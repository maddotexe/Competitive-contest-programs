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

void priority_pree()
{
    int min_arrival_index, x, n, y;
	int t_prev, t_now;
	vector<bool> c;
	vector<vector<int> > v;
	vector<int> c_t, b_t;
	priority_queue<node3> pq;
	struct node3 p;

	cout << "enter the number of processes\n";
	cin >> n;
	v.resize(n+1);
	c.resize(n+1);
	c_t.resize(n+1);
	b_t.resize(n+1);
	x = y = INT_MAX ;
	cout << "enter arrival time, bust time, priority order\n";
	for (int i = 1; i<= n; i++) {
		v[i].resize(3);

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

	t_prev = 0;
	t_now = v[min_arrival_index][0];
	add3(pq, t_prev, t_now, v, c);

	while (!pq.empty()) {
		p = pq.top();
		min_arrival_index = p.i;
		c[min_arrival_index] = 0;
		pq.pop();
		t_prev = t_now;
		t_now = t_prev + 1;
		v[min_arrival_index][1]--;
		if (v[min_arrival_index][1] == 0) {
			c[min_arrival_index] = 1;
		}
		c_t[min_arrival_index] = t_now;
		add3(pq, t_prev, t_now, v, c);
	}

	for (int i = 1; i<= n; i++) {
		cout << v[i][0] << "\t" << b_t[i] << " \t"  << v[i][2] << "\t" << c_t[i] << endl;
	}
}
void priority_non()
{
    int min_arrival_index, x, n, y;
	int t_prev, t_now;
	vector<bool> c;
	vector<vector<int> > v;
	vector<int> c_t;
	priority_queue<node2> pq;
	struct node2 p;

	cout << "enter the number of processes\n";
	cin >> n;
	v.resize(n+1);
	c.resize(n+1);
	c_t.resize(n+1);
	x = y = INT_MAX ;
	cout << "enter arrival time, burst time, priority\n";
	for (int i = 1; i<= n; i++) {
		v[i].resize(3);

		cin >> v[i][0] >> v[i][1] >> v[i][2];
		if (x >= v[i][0]) {
			x = v[i][0];
			if (y >= v[i][2]) {
				y = v[i][2];
				min_arrival_index = i;
			}
		}
		c[i] = 0;
	}

	t_prev = 0;
	t_now = v[min_arrival_index][0];
	add2(pq, t_prev, t_now, v, c);
	while (!pq.empty()) {
		p = pq.top();
		min_arrival_index = p.i;
		pq.pop();
		t_prev = t_now;
		t_now = t_prev + v[min_arrival_index][1];
		c_t[min_arrival_index] = t_now;
		add2(pq, t_prev, t_now, v, c);
	}
	for (int i = 1; i<= n; i++) {
		cout << v[i][0] << "\t" << v[i][1] << " \t"  << v[i][2] << "\t" << c_t[i] << endl;
	}
}
void sjfs_pree()
{
    int min_arrival_index, x, n, y;
	int t_prev, t_now;
	vector<bool> c;
	vector<vector<int> > v;
	vector<int> c_t, b_t;
	priority_queue<node1> pq;
	struct node1 p;

	cout << "enter the number of processes\n";
	cin >> n;
	v.resize(n+1);
	c.resize(n+1);
	c_t.resize(n+1);
	b_t.resize(n+1);
	x = y = INT_MAX ;
	for (int i = 1; i<= n; i++) {
		v[i].resize(2);
		cout << "enter arr, bt\t";
		cin >> v[i][0] >> v[i][1];
		b_t[i] = v[i][1];
		if (x >= v[i][0]) {
			x = v[i][0];
			if (y >= v[i][1]) {
				y = v[i][1];
				min_arrival_index = i;
			}
		}
		c[i] = 0;
	}

	t_prev = 0;
	t_now = v[min_arrival_index][0];
	add(pq, t_prev, t_now, v, c);
	while (!pq.empty()) {
		print(pq);
		p = pq.top();
		min_arrival_index = p.i;
		c[min_arrival_index] = 0;
		cout << "\tindex = " << min_arrival_index << " time = " << v[min_arrival_index][1] - 1 << endl;;
		pq.pop();
		t_prev = t_now;
		t_now = t_prev + 1;
		v[min_arrival_index][1]--;
		if (v[min_arrival_index][1] == 0) {
			c[min_arrival_index] = 1;
		}
		c_t[min_arrival_index] = t_now;
		add(pq, t_prev, t_now, v, c);
	}
	for (int i = 1; i<= n; i++) {
		cout << v[i][0] << "\t" << b_t[i] << " \t" << c_t[i] << endl;
	}
}
void fjfs()
{
    map<int, int > m;
	map<int, int>::iterator it;
	vector<int> a_t, b_t, c_t, t_a_t, w_t;
	int a, b, n, s = 0;
	cout << " enter number o processes \t:";
	cin >> n;
	a_t.resize(n);
	b_t.resize(n);
	c_t.resize(n);
	t_a_t.resize(n);
	w_t.resize(n);
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		m.insert(pair<int, int> (a, b));
		a_t[i] = a;
		b_t[i] = b;
	}
	it = m.begin();
	s = it -> first;
	for (it = m.begin(); it != m.end(); it++) {
		s = s + it -> second;
		c_t[it->first] = s;
		t_a_t[it->first] = c_t[it->first] - it->first;
		w_t[it->first] = t_a_t[it->first] - it->second;
	}

	cout << "proc\arrival\bust\complete\tat\waiting"<< endl;;
	for (int i = 1 ; i <= n; i++)  {
		cout << i << "\t" << a_t[i] << "\t" << b_t[i] << "\t" << c_t[a_t[i]] << "\t" << t_a_t[a_t[i]] << "\t" << w_t[a_t[i]] << endl;
	}

}
void round_robin()
{
    int min_arrival_index, x, n, y;
	int t_prev, t_now, quanta;
	vector<bool> c;
	vector<vector<int> > v;
	vector<int> c_t, b_t;
	queue<int> pq;

	cout << "enter the number of processes\n";
	cin >> n;
	v.resize(n+1);
	c.resize(n+1);
	c_t.resize(n+1);
	b_t.resize(n+1);
	x = y = INT_MAX ;
	for (int i = 1; i<= n; i++) {
		v[i].resize(2);
		cout << "enter arrival time, burst time\t";
		cin >> v[i][0] >> v[i][1];
		b_t[i] = v[i][1];
		if (x >= v[i][0]) {
			x = v[i][0];
			min_arrival_index = i;
		}
		c[i] = 0;
	}
	cout << " enter time quanta\n";
	cin >> quanta;

	t_prev = 0;
	t_now = v[min_arrival_index][0];
	add4(pq, t_prev, t_now, v, c);
	while (!pq.empty()) {

		min_arrival_index  = pq.front();
		pq.pop();

		t_prev = t_now;
		v[min_arrival_index][1] -= quanta;
		if (v[min_arrival_index][1] <=  0) {
			t_now = t_now + quanta + v[min_arrival_index][1];
			c[min_arrival_index] = 1;
			c_t[min_arrival_index] = t_now;
			add4(pq, t_prev, t_now, v, c);
		} else {
			t_now = t_now + quanta;
			c_t[min_arrival_index] = t_now;
			add4(pq, t_prev, t_now, v, c);
			pq.push(min_arrival_index);
		}
	}
	for (int i = 1; i<= n; i++) {
		cout << v[i][0] << "\t" << b_t[i] << " \t" << c_t[i] << endl;
	}


}
void sjfs_non()
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
		cout << "enter arrival time, burst time\t";
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

	t_prev = 0;
	t_now = v[min_arrival_index][0];
	add(pq, t_prev, t_now, v, c);
	while (!pq.empty()) {
		cout << "size = " << pq.size() << endl;
		p = pq.top();
		min_arrival_index = p.i;
		pq.pop();
		t_prev = t_now;
		t_now = t_prev + v[min_arrival_index][1];
		c_t[min_arrival_index] = t_now;
		add(pq, t_prev, t_now, v, c);
	}
	for (int i = 1; i<= n; i++) {
		cout << v[i][0] << "\t" << v[i][1] << " \t" << c_t[i] << endl;
	}
}
int main()
{
    int ch;

        cout << " 0. quiting\n";
	cout << " 1. first job first serve\n";
        cout << " 2. shortest job first non-preemtive\n";
        cout << " 3. shortest job first preemtive\n";
        cout << " 4. priority non-preemtive\n";
        cout << " 5. priority preemtive\n";
        cout << " 6. round robin\n";
        
    while(1) {
    	
        cout << "enter the choice : ";
        cin >> ch;
        if(ch == 0) return 0;

        switch(ch) {

            case 1: {
                fjfs();
                break;
            }

            case 2: {
                sjfs_non();
                break;
            }

            case 3: {
                sjfs_pree();
                break;

            }

            case 4: {
                priority_non();
                break;
            }

            case 5: {
                priority_pree();
                break;
            }

            case 6: {
                round_robin();
                break;
            }
            case 0: {
                cout << "quitting \n";
            }
        }

    }

}

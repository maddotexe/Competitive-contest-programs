
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
	cout << "enter arr, bt, priority\n";
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

	//the process which came first and have min bust time would be executed
	t_prev = 0;
	t_now = v[min_arrival_index][0];
	//cout << " mi = " << min_arrival_index << endl;
	add2(pq, t_prev, t_now, v, c);
	while (!pq.empty()) {
		//cout << "size = " << pq.size() << endl;
		p = pq.top();
		min_arrival_index = p.i;
		//cout << "index = " << min_arrival_index << endl;
		pq.pop();
		t_prev = t_now;
		t_now = t_prev + v[min_arrival_index][1];
		//cout << "t_now = " << t_now << endl;
		c_t[min_arrival_index] = t_now;
		add2(pq, t_prev, t_now, v, c);
	}
	for (int i = 1; i<= n; i++) {
		cout << v[i][0] << "\t" << v[i][1] << " \t"  << v[i][2] << "\t" << c_t[i] << endl;
	}
}






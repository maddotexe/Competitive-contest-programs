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

	//the process which came first and have min bust time would be executed
	t_prev = 0;
	t_now = v[min_arrival_index][0];
	//cout << "t_now = " << t_now << endl;
	add(pq, t_prev, t_now, v, c);
	while (!pq.empty()) {
		//cout << "size = " << pq.size();
		//cout << "t now => " << t_now << "  ->>>>> ";
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
		cout << v[i][0] << "\t" << b_t[i] << " \t" << c_t[i] << endl;
	}
}

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
		cout << "enter arr, bt\t";
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
	//cout << "t_now = " << t_now << endl;
	add4(pq, t_prev, t_now, v, c);
	while (!pq.empty()) {

		//cout << "t now => " << t_now  << "\t" ;
		//print4(pq);

		min_arrival_index  = pq.front();
		//cout << " index chosen = " << min_arrival_index << endl;
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

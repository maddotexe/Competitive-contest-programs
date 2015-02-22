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
//	cout << " s = " << s << endl;
	for (it = m.begin(); it != m.end(); it++) {
		s = s + it -> second;
//		cout << " for " << it -> first << " ct = " << s << endl;
		c_t[it->first] = s;
		t_a_t[it->first] = c_t[it->first] - it->first;
		w_t[it->first] = t_a_t[it->first] - it->second;
	}

	cout << "proc\ta_t\tb_t\tc_t\tt_a_t\tw_t"<< endl;;
	for (int i = 1 ; i <= n; i++)  {
		cout << i << "\t" << a_t[i] << "\t" << b_t[i] << "\t" << c_t[a_t[i]] << "\t" << t_a_t[a_t[i]] << "\t" << w_t[a_t[i]] << endl;
	}

}

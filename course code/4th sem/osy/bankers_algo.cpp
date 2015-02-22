#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int f, n, m, i, j, k, d;
	
	cin >> n;
	cin >> m;
	
	int a[n][m], max[n][m], need[n][m];
	int v[n];
	int av[m];
	
	memset(v, 0, sizeof(v));
	
	cout << "enter the allocated\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	cout << "enter the max\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> max[i][j];
			need[i][j] = max[i][j] - a[i][j];
		}
	}
	
	cout << "need\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << need[i][j] << " ";
		}
		cout << endl;
	}
	
	for (i = 0; i < m; i++)
	cin >> av[i];
	
	k = 0;
	d = n;
	i = 0;
	while (1) {
		f = 1;
		
		if (!v[i]) {
			for (int j = 0; j < m; j++) {
				if (av[j] >= need[i][j]) {
					f = 0;
				} else {
					f = 1;
					break;
				}
			}
		}
		if (!f) {
			for (j = 0; j < m; j++) {
				av[j] += a[i][j];
				cout << av[j] << " ";
			}
			cout << endl;
			v[i] = 1;
			cout << "process = "<< i << endl;
			i = k = 0;
		} else {
			i++;
			k++;
		}
		if (k == d) {
			break;
		}
	}
	
	
	return 0;
}

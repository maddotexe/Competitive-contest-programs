#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long int t, n, m, a, b, w[100][100], sum;
	
	cin >> t;
	int c = 1;
	
	while (t--) {
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> w[i][j];
				if (i == j) {
					w[i][j] = 99999999;
				}
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (w[i][j] > (w[i][k] + w[k][j])) {
						w[i][j] = w[i][k] + w[k][j];
					}
				}
			}
		}
		
		cin >> m;
		sum = 0;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (a != b)
			sum += w[--a][--b];
		}
		cout << "Case #" << c++ << ": " << sum << endl;
	}
	return 0;
}
		

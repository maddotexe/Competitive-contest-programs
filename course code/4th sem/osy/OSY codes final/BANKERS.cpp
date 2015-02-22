#include <iostream>

using namespace std;

bool check(int avl[], int need[], int m)
{
	int i;
	for (i = 0; i < m; i++) {
		if(need[i] > avl[i]) {
			return false;
		}
	}
	if (i == m) {
		return true;
	}
}
int main()
{
	int m;
	int n;

	cout << "Enter Number of process" << endl;
	cin >> m;

	cout << "Enter Number of resources" << endl;
	cin >> n;

	int allot[m][n];
	int max1[m][n];
	int need[m][n];
	int avl[n];
	int status[m];
	cout << "Enter allocation matrix" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> allot[i][j];
		}
	}

	cout << "Enter maximum req  matrix" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> max1[i][j];
		}
	}

	cout << "Enter available resources" << endl;
	for (int i = 0; i < n; i++) {
		cin >> avl[i];
	}
	cout << "need matrix" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			need[i][j] = max1[i][j] - allot[i][j];
			cout << need[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++) {
		status[i] = 0;
	}
	cout << "execution order of processes" << endl;
	for (int i = 0; i < m; i++) {
		if(status[i] == 0) {
			if (check(avl, need[i], n)) {
				cout << i << endl;
				status[i] = 1;
				for (int j = 0; j < n; j++) {
					avl[j] = avl[j] + allot[i][j];
				}
				i = -1;
			}
		}
	}


	cout << endl;
}

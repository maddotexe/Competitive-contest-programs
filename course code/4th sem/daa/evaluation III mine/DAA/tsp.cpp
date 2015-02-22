#include <iostream>
#include <vector>
#define max 100
using namespace std;

bool check(int n, int visit[])
{
	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) return false;
	}
	return true;
}

bool check1(int n, vector<int> visit1)
{
	for (int i = 0; i < visit1.size(); i++) {
		if (visit1[i] == 0) return true;
	}
	return false;
}

int estimate(int a[max][max], int n, int p, vector<int> visit1)
{
	int sum = 0;
	int index;
	int min = a[p][0];
	while(check1(n, visit1)) {
		min = 9999;
		for (int i = 0; i < n; i++) {
			if ((visit1[i] != 1) && (a[p][i] < min)) {
				min = a[p][i];
				index = i;
			}
		}
		visit1[index] = 1;
		sum += min;
		p = index;
	}

	return sum + a[p][0];
}

void bound(int a[max][max], vector<int> visit1, vector<int>& path, int& curbest, int curw, int n, int p, int l)
{
	int e;
	if ((check1(n, visit1))) {
	visit1[p] = 1;
	for (int i = 0; i < n; i++) {
		if ((a[p][i] != 9999) && (visit1[i] != 1)) {
			e = estimate(a, n, p, visit1);
			if (curbest >= e + curw) {
				curbest = e + curw;
				path[l] = i;
				bound(a, visit1, path, curbest, curw + a[p][i], n, i, l + 1);
			} else {
				return;
			}
		}
	}
	}
	if (p == 0) return;
}

int main()
{
	int n;
	cout << "enter no. of nodes : ";
	cin >> n;

	vector<int> visit1 (n, 0);
	vector<int> path (n);
	int a[max][max];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int c = 9999;	
	bound(a, visit1, path, c, 0, n, 0, 0);

	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}
}

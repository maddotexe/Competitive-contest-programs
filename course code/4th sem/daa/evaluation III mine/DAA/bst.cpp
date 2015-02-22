#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int c[100][100];
int x[100][100];

int sum(vector<int> p, int l, int m)
{
	int temp = 0;
	for (int i = l; i <= m; i++) {
		temp += p[i];
	}
	return temp;
}

void cost(vector<int> p, int n, int l, int m)
{
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			l = j;
			m = i + j;
			c[l][m] = c[l][l-1] + c[l+1][m] + sum(p, l, m);
			x[l][m] = l;
			for (int k = l+1; k <= m; k++) {
				int temp = c[l][k-1] + c[k+1][m] + sum(p, l, m);
				if (temp < c[l][m]) {
					c[l][m] = temp;
					x[l][m] = k;	
				}
			}
		}
	}
}

void print_bst(int i, int j)
{
	if (j < i) {
		return;
	}
	print_bst(i, x[i][j]-1);
	cout << x[i][j] << "  ";
	print_bst(x[i][j]+1, j);
}

int main()
{
	int n;
	cout << "enter size: ";
	cin >> n;

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	for (int i = 0; i < n; i++) {
		c[i][i] = p[i];
		x[i][i] = i;
	}
	for (int i = 0; i < n-1; i++) {
		c[i][i+1] = min((2*p[i] + p[i+1]), (p[i] + 2*p[i+1]));
		if ((2*p[i]+p[i+1]) < (p[i]+2*p[i+1])) {
			x[i][i+1] = i+1;
		} else 
			x[i][i+1] = i;
	}
	cost(p, n, 0, n-1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "bst is : " << endl;
	print_bst(0, n-1);
/*	for (int i = 0; i < n; i++) {
		for (int  j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
*/	
}

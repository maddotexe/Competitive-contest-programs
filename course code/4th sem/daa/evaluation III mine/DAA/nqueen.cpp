#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>


using namespace std;

vector <vector <int> > vv;

void print()
{
	for (int i = 0; i < vv.size(); i++) {
		for (int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] << " ";
		}
		if (vv[i].size())
			cout << endl;
	}
}

vector<int> rotate(vector<int> v)
{
	vector<int> v1(v.size());
	for (int i = 0; i < v.size(); i++) {
		v1[v.size()-1-v[i]] = i;
	}
	return v1;
}

vector<int> reflect(vector<int> v)
{
	vector<int> v1(v.size());
	for (int i = 0; i < v.size(); i++) {
		v1[v.size() - 1- i] = v[i];
	}
	return v1;
}

bool issafe(int a[], int r, int n)
{
	for (int i = 0; i < r; i++) {
		if(a[i] == a[r]) {
			return false;
		}
		if ((i - r) * (i - r) == (a[i] - a[r]) * (a[i] - a[r])) {
			return false;
		}
	}
	return true;
}
	
	


bool nqueen(int a[], int r, int n)
{
	if (r == n) {
		if (a[0] == -1) {
			return true;
		}
		vector <int> v;
		
		for (int j = 0; j < r; j++) {
			v.push_back(a[j]);
		}
		vv.push_back(v);
		v.clear();
	}
	
	for (int i = 0; i < n; i++) {
		if (a[r] == -1) {
			a[r] = i;
		
			if (issafe(a, r, n)) {
				if (nqueen (a, r + 1, n) == true) {
					return true;
				} else {
					a[r] = -1;
				}
			} else {
				a[r] = -1;
			}
		}
	}
	return false;
}

void remove_from_vv(vector<vector<int> > v, int a)
{
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j < vv.size(); j++) {
			if (vv[j].size() != 0 && vv[j] == v[i] && a != j) {
				vv[j].resize(0);
			}
		}
	}
}

void rotate_and_reflect(vector <vector <int> > vcheck)
{	
	int c;
	for (int j = 0; j < vv.size(); j++) {
		c = 0;
		if (vv[j].size() != 0) {
			vcheck.push_back(vv[j]);
			c = 0;
			for (int i = 0; i < 3; i++, c++) {
				vcheck.push_back(rotate(vcheck[c]));
			}
			c = 0;
			for (int i = 0; i < 4; i++, c++) {
				vcheck.push_back(reflect(vcheck[c]));
			}
			
			remove_from_vv(vcheck, j);
		}
		vcheck.clear();
	}
}

int main()
{
	int n;
	cin >> n;
	vector <vector <int> > vcheck;
	int a[n];
	memset(a, -1, sizeof(a));
	
	nqueen(a, 0, n);
	cout << vv.size() << endl;
	
/*	for (int i = 0; i < vv.size(); i++) {
		for (int j = 0; j < n; j++) {
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}*/
	rotate_and_reflect(vcheck);
	int c = 0;
	for (int i = 0; i < vv.size(); i++) {
		if (vv[i].size()) {
			c++;
		}
	}
	//print();
	cout << c << endl;
			
	return 0;
}

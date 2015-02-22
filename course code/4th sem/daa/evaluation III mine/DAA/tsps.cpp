#include <iostream>
#include <vector>
#define MIN 9999

using namespace std;

int estimate(vector<vector<int> > weight, int n, int index, int n_e, vector<int> visited)
{
	if (n_e == n - 1) return 0;

	int sum = 0;
	int k;
	int min;
	
	cout <<"index = " << index << endl;

	while (n_e < n - 1) {
		min = MIN;
		for (int i = 0; i < n; i++) {
			if ((min > weight[index][i]) && (!visited[i])) {
				min = weight[index][i];
				k = i;
			}
		}

//		cout << "min_k = " << k << " ";
//		cout << "min = " << min << endl;
		sum += min;
		visited[k] = 1;
		index = k;
		n_e++;
	}

	sum += weight[index][0];

//	cout << "sum = " << sum << endl;
	return sum;
	
}

void tsp(vector<vector<int> > weight, int n, int index, int n_e, vector<int> visited, int& currBest, int currWeight, int path[], int l)
{
	if (n_e != n) {
		visited[index] = 1;
		int esti = estimate(weight, n, index, n_e, visited);
		path[l] = index;

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
//				currWeight += weight[index][i];
				if (currBest >= esti + currWeight) {	
					currBest = currWeight + esti;
				//	cout <<"currBest = " << currBest << endl;
				//	visited[i] = 1;
					tsp(weight, n, i, n_e + 1, visited, currBest, currWeight + weight[index][i], path, l + 1);
				} else {
					return;
				}
			}
		}
	}

	if ((index == 0)) {
//		cout << "returning\n";
		return;
	}
}

int main() 
{
	int n;
	cout << "Enter number of nodes : ";
	cin >> n;
	
	vector<vector<int> > weight (n);
	cout << "Enter the Weight matrix\n";
	for (int i = 0; i < n; i++) {
		vector<int> v (n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		weight[i] = v;
		v.resize(0);
	}

	vector<int> visited (n, 0);
	int currBest = MIN;

	int path[n];

	tsp(weight, n, 0, 0, visited, currBest, 0, path, 0);

	cout << "best = " << currBest << endl;
	for (int i = 0; i < n; i++) {
		cout << path[i] << " -> ";
	}
	cout << "0" << endl;

	return 0;
}

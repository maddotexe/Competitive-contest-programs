#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int> > v;
	priority_queue<pair<int, pair<int, int> > > pri;
	vector<int> parent;
	vector<bool> visited;
	vector<int> weight;
	vector <int> v1;	
	int des, n, a;
	
	cin >> n;
	
	parent.resize(n);
	visited.resize(n);
	weight.resize(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			if (a == 0) 
				v1.push_back(-99);
			else
				v1.push_back(a);
		}
		v.push_back(v1);
		v1.clear();
		weight[i] = 999;
		visited[i] = false;
		parent[i] = 999;
	}

	visited[0] = true;
	parent[0] = 99;
	weight[0] = 0;
	int i = 0;
	for (int j = 0; j < n; j++) {
		if (v[i][j] != -99)
			pri.push(pair <int, pair<int, int> > (-1 * v[i][j] , pair<int, int>(i, j)));
	}
	while (!pri.empty()) {
		pair<int, pair<int, int> > p = pri.top();
		pri.pop();
		des = (p.second).second;
		if (visited[des] == false) {
			weight[des] = p.first;
			parent[des] = (p.second).first;
			visited[des] = true;
			for (int j = 0; j < n; j++) {
				if (v[des][j] != -99 && visited[j] != true) {
					pri.push(pair<int, pair<int, int> >(-1 * v[des][j], pair<int, int>(des, j)));
				}
			}
		}
		i++;
	}
	
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum -= weight[i];
		cout << (char)(i + 65) << " " << (char)(parent[i] + 65) << " " << -weight[i] << endl;
	}
	
	cout << "weight Of minimum spanning tree : " << sum << endl;
	cout << "no of elements in priority queue : " << i << endl;
	return 0;
}

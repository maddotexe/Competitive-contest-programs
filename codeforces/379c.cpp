#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
  
int b[3000010];

int main()
{
	int x, n;
	cin >> n;
	vector <pair<int, int> > a;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(pair <int, int> (x, i));
	}
	
	sort (a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		if (a[i].first == a[i+1].first) a[i+1].first++;
		if (a[i].first > a[i+1].first) a[i+1].first = a[i+1].first + (a[i].first - a[i+1].first) + 1;
	}
	for (int i = 0; i < n; i++) {
		swap (a[i].first, a[i].second);
	}
	sort (a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cout << a[i].second << " ";
	}
	cout << endl;
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	
	cin >> t;
	
	while(t--) {
		int n;
		int ans = 0;
		cin >> n;
		int res = 0;
		for(int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			vector<int> v;
			while(1) {
				if(x < y) swap(x, y);
				if(x % y == 0) {
					v.push_back(x/y - 1);
					break;
				}
				v.push_back(x/y);
				x = x%y;
			}
			int val = v.back();
			for(int i = v.size()-2; i >= 0; i--) {
				if(!v[i]) continue;
				if(val < v[i]) {
					val = v[i];
				}
				else {
					val = v[i]-1;
				}
			//	cout << val << endl;
			}
			res ^= val;
		}
		if(res) cout << "YES\n";
		else cout << "NO" << endl;
	}
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map <int, string> ms;
	map <int, int> mc;
	map <int, int>::iterator it;
	int t, n;
	
	cin >> t;
	string s;
	int x;
	while (t--) {
		cin >> n;
		ms.clear();
		mc.clear();
		for (int i = 0; i < n; i++) {
			cin >> s >> x;
			if (!mc[x]) {
				mc[x]++;
				ms[x] = s;
			} else if (mc[x] == 1) {
				mc[x]++;
			}
		}
		for (it = mc.begin(); it != mc.end(); it++) {
			if (it->second == 1) {
				cout << ms[it->first] << endl;
				break;
			}
		}
		if (it == mc.end()) {
			 cout << "Nobody wins.\n";
		}
	}
}

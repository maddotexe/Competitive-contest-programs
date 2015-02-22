#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map<int, int> m;
	vector<int> v;
	int n;
	cin >> n;
	int size_of_frame = 0;
	cin >> size_of_frame;
	int pagefaults = 0;
	int timer = 1;
	int t;
	while (n--) {
		cin >> t;
		m[t] = timer;
		if (v.size() == 0) {
			v.push_back(t);
			pagefaults++;
		} else {
			if (find(v.begin(), v.end(), t) != v.end()) {
				continue;
			} else {
				pagefaults++;
				if (v.size() < size_of_frame) {
					v.push_back(t);
				} else {
					int flag = 0;
					int mintimer = 9999;
					int in = 0;
					for (int i = 0; i < v.size(); i++) {
						if (m[v[i]] < mintimer && m[v[i]] != 0) {
							in = i;
							mintimer = m[v[i]];
							flag = 1;
						}
					}
					if (flag == 0) {
						v.erase(v.begin());
					} else {
						v.erase(find(v.begin(), v.end(), v[in]));
					}
					v.push_back(t);

				}
			}

		}
		timer++;
	}
	cout << "total pagefaults are " << pagefaults << endl;
	cin >> t;
	return 0;
}

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	int size_of_frame = 0;
	cin >> size_of_frame;
	int pagefaults = 0;
	int t;
	while (n--) {
		cin >> t;
		if (v.size() == 0) {
			v.push_back(t);
			pagefaults++;
		} else {
			if (find(v.begin(), v.end(), t) != v.end()) {
			} else {
				v.push_back(t);
				pagefaults++;
				if (v.size() > size_of_frame) {
					v.erase(v.begin());
				}
			}
		}
	}

	cout << "total pagefaults are " << pagefaults << endl;
	cin >> t;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cout << "enter number of pages" << endl;
	cin >> n;
	cout << "enter size of frame" << endl;
	int size;
	cin >> size;
	int k = 0;
	int pagefaults = 0;
	vector<int> v(n);
	vector<int> temp;
	vector<int> frame;
	for (int k = 0; k < n; k++) {
		cin >> v[k];
	}

	k = 0;
	vector<int>::iterator it;

	while (k < n) {
		if (frame.size() == 0) {
			frame.push_back(v[k]);
			pagefaults++;
		} else if (frame.size() < size) {
			if (find(frame.begin(), frame.end(), v[k]) == frame.end()) {
				pagefaults++;
				frame.push_back(v[k]);
			}
		} else if (frame.size() >= size) {
			if (find(frame.begin(), frame.end(), v[k]) == frame.end()) {
				vector<int> rest;
				for (int j = k + 1; j < n; j++) {
					if (find(frame.begin(), frame.end(), v[j]) != frame.end()) {
						if (find(rest.begin(), rest.end(), v[j]) == rest.end()) {
							rest.push_back(v[j]);
						}
					}
				}
				

				if (rest.size() == 0) {
					frame.erase(frame.begin());
				} else {
					int flag = 0;
					int inside_frame;
					for (int i = 0; i < frame.size(); i++) {
						if (find(rest.begin(), rest.end(), frame[i]) == rest.end()) {
							inside_frame = frame[i];
							flag = 1;
							break;
						}
					}

					if (flag == 1) {
						it = find(frame.begin(), frame.end(), inside_frame);
						frame.erase(it);
					} else {
						if (rest.size() == 0) {
							frame.erase(frame.begin());
						} else {
							it = find(frame.begin(), frame.end(), rest[rest.size() - 1]);
							frame.erase(it);
						}
					}
				}
				frame.push_back(v[k]);

				pagefaults++;
			} 
		}

		k++;
	}

	cout << "the number of pagefaults are " << pagefaults << endl;

	return 0;
}

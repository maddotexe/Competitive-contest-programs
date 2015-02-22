#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input1.in", "r", stdin);
	freopen("output1.out", "w", stdout);
	
	int t, k;
	int a, b;
	int m[4], m1[4];
	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		cin >> a;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> k;
				if (i == a - 1) {
					m[j] = k;
				}
			}
		}
		cin >> b;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> k;
				if (i == b-1) {
					m1[j] = k;
				}
			}
		}
		
		int count = -1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0 ; j < 4; j++) {
				if (m[i] == m1[j]) {
					if (count == -1)
						count = m[i];
					else {
						count = -2;
						break;
					}
				}
			}
		}
	
		cout << "Case #" << cs << ": ";
		if (count == -1) {
			cout << "Volunteer cheated!\n";
		} else if (count == -2) {
			cout << "Bad magician!\n";
		} else {
			cout << count << endl;
		}
	}
    return 0;
}

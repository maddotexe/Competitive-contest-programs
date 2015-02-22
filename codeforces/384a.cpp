#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n & 1) {
		cout << (n/2 + 1) * (n/2 + 1) + (n/2) * (n/2) << endl;
		
		
	} else {
		cout << n / 2 * n << endl;
		
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					cout << "C";
				} else {
					cout << ".";
				}
			} else {
				if (j % 2 == 0) {
					cout << ".";
				} else {
					cout << "C";
				}
			}
		}
		cout << endl;
	}
}

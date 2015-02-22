#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int k = 0;
	int a[100];
	cout << "Enter the max no of people on the table : " << endl;
	cin >> n;
	int p[100] = {0};
	
	while (1) {
			while (1) {
				for (int i = 0; i < (n)/ 2; i ++) {
					if (i == 0) {
						a[i] = (a[(n) / 2 - 1] + 1) % n;
						p[a[i]] = 1;
						cout << a[i] << " : is eating" << endl;
					} else {
						a[i] = (a[i - 1] + 2) % n;
						p[a[i]] = 1;
						cout << a[i] << " : is eating" << endl;
					}
				}
				int i1;
				for (i1 = 0; i1 < n; i1 ++) {
					if (p[i1] == 0) {
						cout << "Some are remaining to eat" << endl;
						break ;
					}
				}
				if (i1 == n) {
					cout << "processes completed " << endl;
					break ;
				}
			}
			break;
	}
	
	cin >> k;
	return 0;
}
	

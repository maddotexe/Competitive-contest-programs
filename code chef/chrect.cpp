#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	int n, m, k;
	
	cin >> t;
	
	while (t--) {
		cin >> n >> m >> k;
		
		if ((n == 1 && m == 2) || (n == 2 && m == 1) || (m == 1 && n == 1)) {
			printf("0\n");
			continue;
		}
		
		if (n == 1 || m == 1) {
			cout << k << endl;
			continue;
		}
		
		cout << (k + (k & 1)) / 2 << endl;
	}
	
	return 0;
}
			

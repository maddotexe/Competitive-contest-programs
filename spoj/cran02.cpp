#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t, n, x, p, y, f;
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		int c = 0;
		int sum = 0;
		int p = c;
		int d = 0;
		scanf("%d", &x);
		if (x == 0) {
			c++;
			//cout << c << endl;
		}
		for (int i = 1; i < n; i++) {
			scanf("%d", &y);
			f = 1;
			if (y == 0) {
				if (x != 0) {
					sum += (c * (c + 1)) / 2;
					c = 0;
				}
				c++;
				//cout << " " << c << endl;
				d = 0;
			}
			
			if (y != 0) {
				if (x == -1 * y) {
					c++;
					//cout << "first 1\n";
					d = 0;
				} else {
					d++;
					//cout << "second1\n";
				}
			}
			if (x != -1 * y && d == 2) {
				sum += (c * (c + 1)) / 2;
				c = 0;
				d = 0;
				//cout << "third\n";
			}
			if (i == n - 1) {
				sum += (c * (c + 1)) / 2;
			}	
			x = y;
					
			
		}
		
		cout << sum << endl;
	}
	
	return 0;
}
				

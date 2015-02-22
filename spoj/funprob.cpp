#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, m;
	double x;
	
	scanf("%d%d", &n, &m);
	while (1) {
		if (n == 0 && m == 0) {
			return 0;
		}
		x = 0.0;
		if (n > m) {
			cout << "0.000000" << endl;
		} else {
			x = (double)(m - n + 1) / double(m + 1);
		
			printf("%lf\n", x);
		}
		scanf("%d%d", &n, &m);
		
		
	}
	
	return 0;
}

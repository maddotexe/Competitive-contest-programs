#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	double a, b, c, d;
	int t;
	
	cin >> t;
	
	while (t--) {
		cin >> a >> b >> c >> d;
		double e = a / (a + b);
		
		printf("%.7f\n", e);
	}
	return 0;
}

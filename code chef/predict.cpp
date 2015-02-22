#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	double f;
	
	cin >> t;
	
	while (t--) {
		cin >> f;
		
		double y = 10000 * f;
		double z = 10000 * (1 - f);
		
		y = y + 2 * (1 - f) * y;
		z = z + 2 * (f) * z;
		
		cout << max (y, z) << endl;
	}
	
	return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int ans = n;
	
	while (n >= m) {
		ans += n / m;
		
		int t = n % m;
		n /= m;
		n += t;
	}
	cout << ans << endl;
	return 0;
}

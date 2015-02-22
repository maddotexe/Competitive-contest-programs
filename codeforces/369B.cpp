#include <iostream>
#include <cstdio> 
#include <cstring>

using namespace std;

int main()
{
	int n, k, l, r, sa, sk;
	cin >> n >> k >> l >> r >> sa >> sk;
	int tmp = sk % k;
	int a[n];
	memset(a, 0, sizeof(a));
	
	for (int i = 0; i < k; i++) {
		a[i] = sk / k;
	}
	for (int i = 0; i < tmp; i++) {
		a[i]++;
	}
	
	sa = sa - sk;
	if (n - k > 0) 
	tmp = sa % (n - k);
	else {
		for (int i = 0 ;i < k; i++) {
			cout << a[i]<< " ";
		}
		return 0;
	}
	for (int i = k; i < n; i++) {
		a[i] = sa / (n - k);
	}
	for (int i = k; i < k + tmp; i++) {
		a[i]++;
	}
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
		
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int l = 3;
	int b[2 * l], c[l][l], a[l][l];;
	int sum = 0;
	for (int i = 0; i < l; i++) {
		b[i] = i;
		sum += i;
	}	
	b[l] = sum;
	for (int i  = l + 1; i < 2 * l - 1; i++) {
		sum = 0;
		for (int j = i - 1; j >= i - l; j--) {
			sum += b[j];
		}
		b[i] = sum;
	}
	
	for (int i = 0; i < l; i++) {
		int d = i;
		for (int j = 0; j < l; j++) {
			c[i][j] = b[2 * l - d - 2];
			d++;
		}
	}
	memset(a, 0, sizeof(a));
	for (int i = 0; i < l - 1; i++) {
		a[i][0] = 1;
		a[i][i + 1] = 1;
	}
	a[l - 1][0] = 1;
	
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
		
	
	
	return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fp;
	long long int j, k, c;
	fp.open("catalan_numbers_upto_1000.txt");
	long long int a[1002];
	a[0] = a[1] = 1;
	for (int i = 2; i < 1002; i++) {
		j = i - 1;
		k = 0;
		c = 0;
		while (j >= i / 2) {
			c += (2 * a[j] * a[k]) % 1000000;
			c %= 1000000;
			j--;
			k++;	
		}
		if (i & 1) {
			c -= (a[j + 1] * a[k - 1]) % 1000000;
			c %= 1000000;
			if (c < 0) {
				c += 1000000;
			}
		}
		a[i] = c;
		fp  << c << ", ";
	}

	
	return 0;
}

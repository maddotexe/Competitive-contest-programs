#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[10001];

void sieve()
{
	a[0] = a[1] = 1;
	for (int i = 2; i < 10001; i++) {
		if (!a[i]) {
			for (int j = i * i; j < 10001; j += i) {
				a[j] = 1;
			}
		}
	}
}

int main()
{
	memset(a, 0, sizeof(a));
	sieve();
	int n, c = 0;
	cin >> n;
	FILE *fp = fopen("out.txt", "w");
	for (int j = 1; j < 10001; j++) {
		c = 0;
		for (int i = 2; i < j / 2; i++) {
			if (!a[j - 2 * i] && !a[i]) {
				c++;
			}
		}
		fprintf(fp, "%d,", c);
	}
	return 0;
}

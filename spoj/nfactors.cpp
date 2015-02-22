#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[1000010];
int f[10][1000010];
void sieve()
{
	memset(a, 0, sizeof(a));
	for (int i = 2; i < 1001; i++) {
		if (!a[i])
		for (int j = i; j < 1000001; j += i) {
			a[j]++;
		}
	}
}

int main()
{
	sieve();
	int t, n, d, b;
	scanf("%d", &t);
	memset(f, 0, sizeof(f));
	for (int i = 2; i < 1000001; i++) {
		if (a[i] == 1) {
			f[0][i] = f[0][i - 1] + 1;
		} else {
			f[0][i] = f[0][i - 1];
		}
		if (a[i] == 2) {
			f[1][i] = f[1][i - 1] + 1;
		} else {
			f[1][i] = f[1][i - 1];
		}
		if (a[i] == 3) {
			f[2][i] = f[2][i - 1] + 1;
		} else {
			f[2][i] = f[2][i - 1];
		}
		if (a[i] == 4) {
			f[3][i] = f[3][i - 1] + 1;
		} else {
			f[3][i] = f[3][i - 1];
		}
		if (a[i] == 5) {
			f[4][i] = f[4][i - 1] + 1;
		} else {
			f[4][i] = f[4][i - 1];
		}
		if (a[i] == 6) {
			f[5][i] = f[5][i - 1] + 1;
		} else {
			f[5][i] = f[5][i - 1];
		}
		if (a[i] == 7) {
			f[6][i] = f[6][i - 1] + 1;
		} else {
			f[6][i] = f[6][i - 1];
		}
		if (a[i] == 8) {
			f[7][i] = f[7][i - 1] + 1;
		} else {
			f[7][i] = f[7][i - 1];
		}
		if (a[i] == 9) {
			f[8][i] = f[8][i - 1] + 1;
		} else {
			f[8][i] = f[8][i - 1];
		}
		if (a[i] == 10) {
			f[9][i] = f[9][i - 1] + 1;
		} else {
			f[9][i] = f[9][i - 1];
		}
		
	}
	
	while (t--) {
		int c = 0;
		scanf("%d%d%d", &d, &b, &n);
		if (!n) {
			if (d == 1) 
				printf("1\n"); 
			else 
				printf("0\n"); 
		} else 
			printf("%d\n", f[n - 1][b] - f[n - 1][d - 1]);
	}
	
	return 0;
}

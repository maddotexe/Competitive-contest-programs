#include <iostream>

using namespace std;

int main()
{
	int n;
	
	scanf("%d", &n);
	
	char a[n][n], x;
	int b[n][n];
	int c = 0;
	for (int i = 0; i < n; i++) {
		getchar();
		for (j = 0; j < n; j++) {
			c = getchar();
			a[i][j] = c;
			if (c == 'W') {
				w++;
			} else {
				b++;
			}
		}
	}
	
	memset(b, '0', sizeof(b));
	
	if (w >= b) {
		x = 'W';
	} else {
		c++;
		x = 'B';
	}
	
	for (i= 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] == x) {
				b[i][j] = 1;
				continue;
			} else {
				k = i;
				l = j;
				while (
				
	
	
	

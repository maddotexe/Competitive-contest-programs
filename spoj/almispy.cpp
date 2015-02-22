
#include <stdio.h>
 
void fast(long long int a[2][2], long long int n, long long int m) {
	if (n == 1) {
		return;
	}
	long long int b[2][2];
	fast(a, n / 2, m);
	b[0][0] = ((a[0][0]*a[0][0]) + (a[0][1]*a[1][0])) % m ;
	b[0][1] = ((a[0][0]*a[0][1]) + (a[0][1]*a[1][1])) % m;
	b[1][0] = ((a[1][0]*a[0][0]) + (a[1][1]*a[1][0])) % m;
	b[1][1] = ((a[1][0]*a[0][1]) + (a[1][1]*a[1][1])) % m;

	a[0][0] = b[0][0];
	a[0][1] = b[0][1];
	a[1][0] = b[1][0];
	a[1][1] = b[1][1];

	if (n & 1) {
		b[0][0] = ((a[0][0]*0) + (a[0][1]*1)) % m;
		b[0][1] = ((a[0][0]*1) + (a[0][1]*2)) % m;
		b[1][0] = ((a[1][0]*0) + (a[1][1]*1)) % m;
		b[1][1] = ((a[1][0]*1) + (a[1][1]*2)) % m;
		
		a[0][0] = b[0][0];
		a[0][1] = b[0][1];
		a[1][0] = b[1][0];
		a[1][1] = b[1][1];
	}
 
	return;
	
}


int main()
{
	int t;
	
	long long int n, m, a[2][2];
	
	scanf("%d", &t);
	
	while (t--) {
		a[0][0] = 0;
		a[0][1] = a[1][0] = 1;
		a[1][1] = 2;
		scanf("%lld%lld", &n, &m);
		if(n == 1) {
            		printf("3 5\n");
            		continue;
        	}
		long long int d;
		fast(a, n, m);
		
		//cout << a[0][0] << " " << a[0][1] << endl << a[1][1] << " " << a[0][1] << endl;
		long long int g = a[1][1];
		long long int h = a[1][0];
		//cout << g << " " << h << endl;
		d = ((g * g) - (h * h)) % m;
		long long int e = ((g * g) + (h * h)) % m;
		long long int f = (2 * g * h) % m;
		
		if (d < 0)  d += m;
		
		if (!(n&1)) {
			d = f;
		}
		
		printf("%lld %lld\n", d, e);
		
	}
}
		

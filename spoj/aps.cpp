#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

long long int a[10010000];

long long int b[10000000];
void pre() {
    a[0] = a[1] = 0;
	for (int i = 2; i < 10000000; i++) {
		if(!a[i]) {
			a[i] = i;
		for (long long int j = i * i; j < 10010000; j += i) {
			if (!a[j])
				a[j] = i;
		}}
	}
	
	b[0] =b[1] = 0;
	for (int i = 2; i < 10000000; i++) {
		b[i] = b[i - 1] + a[i];
	}
}

int main()
{
	memset(a, 0, sizeof(a));
	pre();
	int n;
	
	int t;
	
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", b[n]);
	}
	
	return 0;
}



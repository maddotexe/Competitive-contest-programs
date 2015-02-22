#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


int main()
{
	int t, i;
	int a[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
	string s;
	scanf("%d", &t);
	int k;
	
	while (t--) {
		
		cin >> s;
		i = 0;
		k = 0;
		while (i < s.size() - 1) {
			if (s[i] == s[i + 1]) {
				k++;
			}
			i++;
		}
		
		printf("%ld\n", a[k]);
	}
	
	return 0;
}

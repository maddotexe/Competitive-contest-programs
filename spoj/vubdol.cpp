#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
	int a[] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352};
	
	int n, i, k, x, j;
	
	scanf("%d", &n);
	
	while (1) {
		if (n == 0) return 0;
		map<int, int> m;
		map<int, int>::iterator it;
		for (i = 0; i < n; i++) {
			scanf("%d", &x);
			j = 0;
			while (x >= a[j]) {
				j++;
			}
			
			if (a[j] - x <= x - a[j - 1]) {
				m[a[j]]++;
			} else {
				m[a[j - 1]]++;
			}
			
		}
		
		for (it = m.begin(); it != m.end(); it++) {
			
			
			for (i = 0; i < it->second; i++) {
				printf("%d ", it->first);	
			}
			
		}
		printf("\n");
		scanf("%d", &n);
	}
	
	return 0;
}
	
			

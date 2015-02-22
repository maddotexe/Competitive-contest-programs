#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int tree[100010];
int a[100001];
int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= 100000){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int main()
{
	char c;
	
	int n, x, y, m;
	int sum[100010];
	memset(tree, 0, sizeof(tree));
	
	cin >> n;
	sum[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i)
			sum[i] = a[i] + sum[i - 1];
		else 
			sum[i] = a[i];
	}
	
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		scanf("%c%d%d", &c, &x, &y);
		
		if (c == 'U') {
			update(x, a[x] - y);
			a[x] = y;
		} else {
			printf("%d\n", read(y-1) - read(x));
		}
	}
	
	return 0;
}
	

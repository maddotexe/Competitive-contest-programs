#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int t;
	int k = 1, i;
	char s[100];
	
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		map<string, int> v;
		map<string, int>::iterator it;
		getchar();	
		for (i = 0; i < n; i++) {
			gets(s);
			v[(string)s]++;
		}
		for (it = v.begin(); it != v.end(); it++) {
			printf("%s%d\n", it->first.c_str(), it->second);
		}
		printf("\n");
	}
	
	return 0;
}

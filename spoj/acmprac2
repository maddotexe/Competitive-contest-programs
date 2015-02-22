#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	vector <int> v;
	vector<int>::iterator it;
	int t;
	int i;
	int c = 0;
	int n;
	int l;
	string str;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		cin >> str;
		l = str.length();
		for(i = 0; i < l; i++) {
			if(str[i] == str[i+1]){
				c++;
			}
			else {
				c++;
				v.push_back(c);
				c = 0;
			}
		}
		sort(v.rbegin(), v.rend());
		c =0;
		it = v.begin();
		for(it, i= 0; i < n; i++,it++) {
			c = c + *it;
		}
		printf("%d\n", c);
		v.clear();
		str = "";
		c = 0;
	}
	return 0;
}
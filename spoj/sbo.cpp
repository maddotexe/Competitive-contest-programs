#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> v(100005);
int a[500001];

int main()
{
	int n;
	
	scanf("%d", &n);
	int d = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int l = 0, r = 0;
	int max = 1;
	while (r < n) {
		if (v[a[r]] == 0) {
			v[a[r]]++;
			d++;
			
			if (d > max) {
				max = d;
			}
			r++;
		} else {
			if (l + 1 == r) {
				v[a[l]] = 0;
				l++;
				d = r - l;
			} else {
				while (a[l] != a[r]) {
					
					v[a[l++]] = 0;
				}
				
				d = r - l;
			}
			
			if (d > max) {
				max = d;
			}
		}
		
		
		
	}
	cout << max << endl;
	return 0;
}

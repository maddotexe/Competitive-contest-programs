#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
 
using namespace std;
 
string v[500000];

void quicksort(string a[500000], int l , int h, int n)
{
     int l1 =l;
     int h1 = h;
     if(l > h)
     return;
     int p; 
     string temp;
     p = a[l].size();
     while(l < h)
     {
             while( a[l].size() < p)
             {
                 l++;
             }
             while( a[h].size() > p)
             {
                 h--;
             }
     temp = a[h];
     a[h] = a[l];
     a[l] = temp;
     }
     
     quicksort(a, l1, h-1,n);
    quicksort(a, h+1,h1,n);
     
}

int main()
{
	int n, r, c, sum, t, i, j;
	char ch;
	string s;
	scanf("%d", &n);
	map<char, int> m1;
	map<char, int> m;
	map<char, int>::iterator it;
 
 
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
 
	quicksort (v, 0, n - 1, n);
 
	scanf("%d%d%d", &r, &c, &t);
	int tot;
	int f;
	while (t--) {
		f = 0;
		tot = r * c;
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				cin >> ch;
				m[ch]++;
			}
		}
 
		for (i = 0; i < n; i++) {
			if (tot < v[i].size()) {
				continue;
			}
			if (m[v[i][j]] == 0){
                continue;
			}
			sum = 0;
			for (j = 0; j < v[i].size(); j++) {
				m1[v[i][j]]++;
				sum++;
				if (m1[v[i][j]] > m[v[i][j]]) {
					break;
				}
			}
 
			if (j == v[i].size()) {
				f++;
				tot -= sum;
				for (it = m1.begin(); it != m1.end(); it++) {
					m[it->first] -= it->second;
				}
				i = 0;
			}
			m1.clear();
		}
		if (f & 1)  {
			printf("Alice\n");
		} else {
			printf("Bob\n");
		}
		m.clear();
	}
 
	return 0;
}

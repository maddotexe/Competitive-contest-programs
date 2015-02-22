#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
 
using namespace std;
 
string v[500010];
string c[500010];

void merge (string a[], int l, int h)
{
     int i = l, j ,k = l;
     int mid = (l + h) / 2;
     j = mid + 1;
     while(i <=mid &&  j <= h)
     {
         if(a[i].size() < a[j].size())
         {
                 c[k] = a[i];
                 i++;
                 k++;
         }
         else
         {
                 c[k] = a[j];
                 j++;
                 k++;
         } 
     }
     while( i <= mid)
     {
            c[k] = a[i];
            
            k++;
            i++;
     }
      while( j <= h)
     {
            c[k] = a[j];
            k++;
            j++;
     }
     for (i = l; i < k; i++)
     {
         a[i] = c[i];
     }
}
       
void mergesort(string a[], int l, int h)
{
     int mid;
     if (l >= h)
     return;
     mid = (l + h)/ 2;
     mergesort(a, l,mid);
     mergesort(a, mid+1,h);
     merge(a, l, h);
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
 	
	mergesort (v, 0, n - 1);
 	
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
 
		for (i = n-1; i >= 0; i--) {
			
			if (tot < v[i].size()) {
				continue;
			}
			if (m[v[i][0]] == 0){
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
				//cout << v[i] << endl << endl;
				for (it = m1.begin(); it != m1.end(); it++) {
					m[it->first] -= it->second;
				}
				i = n;
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

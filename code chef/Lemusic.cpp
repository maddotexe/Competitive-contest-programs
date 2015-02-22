#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

inline void fastRead(long long int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}

int main()
{
	int n, k, t;
	long long int a, b;
	cin >> t;
	
	while (t--) {
		cin >> n;
		map<long long int, long long int> m;
		map<long long int, long long int>::iterator it;
		vector <long long int> v, v1;
		unsigned long long int sum = 0;
		for (int i = 0; i < n; i++) {
			fastRead(&a);
			fastRead(&b);
		
			if (m[a] == 0) {
				m[a] = b;
			} else if (m[a] > b) {
				v.push_back(m[a]);
				m[a] = b;
			} else {
				v.push_back(b);
			}
		}
		
		for (it = m.begin(); it != m.end(); it++) {
			v1.push_back(it->second);
		}
		
		sort (v1.begin(), v1.end());
		
		for (int i = 0; i < v1.size(); i++) {
			sum += v1[i] * (i + 1);
		}
		
		for (int i = 0; i < v.size(); i++) {
			sum += v[i] * v1.size();
		}
		
		printf("%lld\n", sum);
	}
	
	return 0;
}
		
		

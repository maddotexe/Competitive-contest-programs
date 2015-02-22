#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
 
using namespace std;

#define max 100007

int a[max] = {0};
int y = 0;

void sieve()
{
        for(int i = 2; i <= max; i++){
                if (a[i] != 0)
			continue;
		a[i]++;
                for(int j = 2 * i; j <= max; j += i) {
                        a[j]++;
                }        
        }        
}

int main()
{
	sieve();
	int a1, b, k, t, c;
	
	cin >> t;
	
	while (t--) {
		c = 0;
		cin >> a1 >> b >> k;
		
		for (int i = a1; i <= b; i++) {
			if (a[i] == k) {
				c++;
			}
		}
		cout << c << endl;
	}
	return 0;
}

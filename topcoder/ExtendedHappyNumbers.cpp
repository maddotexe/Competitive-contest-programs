#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;



class ExtendedHappyNumbers {
public:
	map<long long, int> m;
	long long po(long long x, int k) {
		long long a = 1;
		for (int i = 0; i < k; i++) {
			a *= x;
		}
		return a;
	}
	long long calcTheSum(int, int, int);
};

long long ExtendedHappyNumbers::calcTheSum(int a, int b, int k) {
	m.clear();
	long long int sum = 0;
	for (int i = a; i <= b; i++) {
		long long x = i;
		long long c = 0, f = i;
		m.clear();
		while (m[x] != 1) {
			c = 0;
			m[x]++;
			while (x != 0) {
				c += po(x % 10, k);
				x /= 10;
			}
			
			x = c;
			//cout << c << endl;
			f = min(f, c);
			//sum1 = c;
			//cout << sum1 << endl;
			//cout << f << endl;
		}
		cout << f << endl;
		sum += f;
	}
	return sum;		
}

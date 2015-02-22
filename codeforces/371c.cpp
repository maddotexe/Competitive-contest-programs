#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	long long a, b, c, aa, bb, cc, x = 0, y = 0, z = 0, count = 0, xa, xb, xc, r, xx, d;
	cin >> s >> a >> b >> c >> aa >> bb >> cc >> r;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'S') {
			y++;
		} 
		if ( s[i] == 'B') x++;
		if (s[i] == 'C') z++;
	}
//	cout << x << " " << y << " " << z << " " << endl;
	if (x > 0) {
		xa = a / x;
	} else {
		xa = 0;
		a = 0;
	}
	if (y > 0) {
		xb = b / y;
		
	} else {
		xb = 0;
		b = 0;
	}
	if (z > 0) {
		xc = c / z;
	} else {
		xc = 0;
		c = 0;
	}
	
	xx = min(xa, min(xb, xc));
	
	count += xx;
	a -= xx * x;
	b -= xx * y;
	c -= xx * z;
//	cout << a << " " << b << " " << c << " " << count << endl;
	while (a != 0 || b != 0 || c != 0) {
		if (x > 0) {
		
			if (a >= x) a-=x;
			else {
				d = x - a;
				a = 0;
				r -= d * aa;
			}
		}
		if (y > 0) {
		
			if (b >= y) b-=y;
			else {
				d = y - b;
				b = 0;
				r -= d * bb;
			}
		}
		if (z > 0) {
		
			if (c >= z) c-=z;
			else {
				d = z - c;
				c = 0;
				r -= d * cc;
			}
		}
		
		if (r >= 0) {
			count++;
		} else {
			break;
		}
//		cout << count << " " << r << endl;
	}
	
	count += r / (x * aa + y * bb + z * cc);
	
	cout << count << endl;
	
}

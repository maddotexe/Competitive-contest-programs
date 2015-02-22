#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define ln long long int

using namespace std;

ln Avalue(vector<bool> a, int n)
{
	ln sum = 0;
	int w = 1;
	for (int i = n-1; i >= 0; i--) {
		sum += a[i]*w;
		w *= 2;
	}
	return sum;
}

int main()
{
	bool gen2[] = {true, false, false, true, true};
	vector<bool> gen(gen2, gen2+5);
	char c;
	vector<bool> poly;
	vector<bool> polyB;
	
	int gen_sz = gen.size();

	while (c = getchar()) {
		if (c == '\n') {
			break;
		}
		poly.push_back(c - 48);
	}

	for (int i = 1; i < gen_sz; i++) {
		poly.push_back(0);
	}

	polyB.resize(poly.size());
	polyB = poly;

	int poly_sz = poly.size();
	int j = 0;
	ln v_gen = Avalue(gen, gen_sz);
	while (1) {
		int k = 0;
		if (poly[j]) {
			for (int i = j; i < j+gen_sz; i++) {
				poly[i] = (poly[i] ^ gen[k++]);
			}
		}
		ln n2 = Avalue(poly, poly_sz);
		if (n2 < 15) {
			break;
		}
		j++;
	}
	int l = 0;
	for (l = 0; l < poly_sz-gen_sz+1; l++) {
		cout << poly[l];
	}
	cout << "  ";
	for ( ; l < poly_sz; l++) {
		cout << poly[l];
	}
	cout << endl;

	j = 0;
	while (1) {
		int k = 0;
		if (polyB[j]) {
			for (int i = j; i < j+gen_sz; i++) {
				polyB[i] = (polyB[i] ^ gen[k++]);
			}
		}

		ln n2 = Avalue(polyB, poly_sz);
		if (n2 == 0) {
			cout << "Remainder justitied " << endl;
			break;
		}
		j++;
	}

	return 0;
}

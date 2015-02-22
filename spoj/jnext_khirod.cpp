#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstdio>

using namespace std;

void func(vector<int> &v)
{
	// 2665 or 2932 i.e, sequence violated at index 1 then
	// for 2665 - 5662
	// for 2932 - 3229
	// for 2662 - 6226
	// for 12842 -> 14822 -> 14228

	bitset<10> bits;
	int pos, temp;

	for (int i = v.size() - 1; i > 0; i--) {
		bits.set(v[i]);
			if (v[i] > v[i-1]) {
			// sequence disturbed here.
				int k;
				pos = i;
				for (k = v[i-1]+1; k < 10; k++) {
					if (bits.test(k) && k != v[i-1]) {
						break;	
					}
				}
//				cout << "K: " << k << endl;
					
				for (int j = i; j < v.size(); j++) {
					if (v[j] == k) {
						swap(v[j], v[i-1]);
						goto sort;
					}
				}

			}
	}

	printf("-1\n");
	return;

	sort:
	sort(v.begin()+pos, v.end());
	int size = v.size();
	for (int i = 0; i < size; i++) 
		printf("%d",v[i]);
	printf("\n");
}
				 	
int main()
{
	int num, n, t;
	vector<int> v;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &num);
			v.push_back(num);
		}
		func(v);
		v.clear();
	}
}
		


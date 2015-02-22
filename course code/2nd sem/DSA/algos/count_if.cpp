#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
bool IsOdd(int i)
{
	return ((i%2) == 1);
}
 
int main () {
	int total;
 
	vector<int> v;
	for (int i = 1; i < 10; i++) {
		v.push_back(i);
	}
 
	total = (int) count_if(v.begin(), v.end(), IsOdd);
	cout << "v contains " << total  << " odd numbers" << endl;
 
	return 0;
}


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
 

 	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
 
	replace_if(v.begin(), v.end(), 1, 0);

 	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
getchar();
getchar(); 
	return 0;
}


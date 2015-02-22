#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ptr_vec(vector<int> &v)
{
	for (int i = 0; (int) i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void ptr_arr(int a[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main () {
	int arr[] = {9, 2, 1, 4};

	vector<int> v(arr, arr + 4);

	ptr_vec(v);
	sort(v.begin(), v.end());
	ptr_vec(v);

	ptr_arr(arr, sizeof(arr)/sizeof(int));
	sort(arr, arr + 4);
	ptr_arr(arr, sizeof(arr)/sizeof(int));
	getchar();
	getchar();
	
 
	return 0;
}


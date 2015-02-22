#include <iostream>
#include <algorithm>

using namespace std;
 
int main () {
	int arr[] = {9, 2, 1, 4};
 
	sort(arr, arr + 4);
 
	do {
		for (int i = 0; i < 4; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	} while (next_permutation(arr, arr + 4));
 getchar();
 getchar();
	return 0;
}


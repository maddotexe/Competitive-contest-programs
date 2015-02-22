#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
 
int main () {
	int total;
 
	// counting elements in array
	int arr[] = {1, 1, 3, 3, 5, 1, 1, 5};
	total = (int) count(arr, arr + 8, 1);
	cout << "(array)  1 appears " << total << " times\n";
 
	// counting elements in vector
	vector<int> v(arr, arr + 8);
	total = (int) count(v.begin(), v.end(), 5);
	cout << "(vector) 5 appears " << total << " times\n";
 
	// counting elements in list
	list<int> lst(arr, arr + 8);
	total = (int) count(lst.begin(), lst.end(), 3);
	cout << "(list)   3 appears " << total << " times\n";
 getchar();
 getchar();
	return 0;
}


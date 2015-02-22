#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;

int fun_1(int x, int y) {
	return (x + (2 * y));
}

int main () {
	int arr[] = {01, 20,30};

	cout << "arr: using default accumulate: ";
	cout << accumulate(arr, arr + 3, 100,fun_1);
	cout << endl;

	cout << "arr: using functional's minus: ";
	cout << accumulate(arr, arr + 3, 100, minus<int>());
	cout << endl;

	cout << "arr: using custom function: ";
	cout << accumulate(arr, arr + 3, 100, fun_1);
	cout << endl << endl;

	vector<int> v(arr, arr + 3);
	cout << "v: using default accumulate: ";
	cout << accumulate(v.begin(), v.end(), 100);
	cout << endl;

	cout << "v: using functional's minus: ";
	cout << accumulate(v.begin(), v.end(), 100, minus<int>());
	cout << endl;

	cout << "v: using custom function: ";
	cout << accumulate(v.begin(), v.end(), 100, fun_1);
	cout << endl << endl;

	list<int> lst(arr, arr + 3);
	cout << "lst: using default accumulate: ";
	cout << accumulate(lst.begin(), lst.end(), 100);
	cout << endl;

	cout << "lst: using functional's minus: ";
	cout << accumulate(lst.begin(), lst.end(), 100, minus<int>());
	cout << endl;

	cout << "lst: using custom function: ";
	cout << accumulate(lst.begin(), lst.end(), 100, fun_1);
	cout << endl;

	list<int>::iterator it = lst.begin();
	advance(it, 2);
	cout << "lst: using custom function: ";
	cout << accumulate(lst.begin(), it, 0, fun_1);
	cout << endl;
getchar();
getchar();
	return 0;
}


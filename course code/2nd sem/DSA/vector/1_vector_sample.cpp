#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;

	for (int i = 0; i < 7; i++) {
		v.push_back(i);
		cout << "v.size() = " << v.size() << endl;
	}
	cout << endl;

	for (int i = 0; i < (int) v.size(); i++) {
		cout << "v[" << i << "] = " << v[i] << endl;
	}

	return 0;
}


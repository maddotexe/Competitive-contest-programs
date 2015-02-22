#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> m;

	for (int i = -20; i < 20; i += 5) {
		m.insert(pair<int, int>(i, i * i));
	}

	cout << "m.size() = " << m.size() << endl;
	for (int i = -20; i < 20; i += 5) {
		cout << i << " " << m[i] << endl;
	}
	cout << endl;

	cout << "m.size() = " << m.size() << endl;
	for (int i = -20; i < 20; i++) {
		if (m.count(i)) {
			cout << i << " " << m[i] << endl;
		}
	}

	return 0;
}


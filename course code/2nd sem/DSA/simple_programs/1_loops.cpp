#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 4; i++) {
		int j = 0;
		while (j <= i) {
			cout << "i = " << i << ", j = " << j << endl;
			j++;
		}
		cout << endl;
	}

	return 0;
}


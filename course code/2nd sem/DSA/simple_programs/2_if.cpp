#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 7; i++) {
		if (i != 3) {
			cout << "i = " << i << endl;
		} else {
			cout << "  = " << endl;
		}
	}

	return 0;
}


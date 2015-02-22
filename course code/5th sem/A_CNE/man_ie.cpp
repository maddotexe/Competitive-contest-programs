#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	string htol = "10";
	string ltoh = "01";
	char c;
	while ((c = getchar()) && (c != '\n')) {
		if (c^'1') {
			cout << htol;
		} else {
			cout << ltoh;
		}
	}
	cout << endl;

	return 0;
}

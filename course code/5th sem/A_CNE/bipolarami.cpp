#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char c;
	int k = 1;
	while ((c = getchar()) && (c != '\n')) {
		if (c == '0') {
			cout << "0";
		} else {
			if (k) {
				cout << "+";
			} else {
				cout << "-";
			}
			k++;
			k %= 2;
		}
	}
	cout << endl;

	return 0;
}

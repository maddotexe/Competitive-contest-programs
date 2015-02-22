#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char c;
	int k = 0;
	while ((c = getchar()) && (c != '\n')) {
		cout << c;
		if (c == '1') {
			k++;
		}
	}
	cout << k%2 << endl;

	return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char c = getchar();
	cout << c;
	char prev = c;
	while ((c = getchar()) && (c != '\n')) {
		if (c == '1') {
			if (prev == '1') {
				prev = '0';
			} else {
				prev = '1';
			} 
		}
		cout << prev;
	}
	cout << endl;

	return 0;
}

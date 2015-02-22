#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char c = getchar();
	cout << c;

	if (c == '0') {
		c = '1';
	} else {
		c = '0';
	}

	cout << c;
	char prev = c;
	while ((c = getchar()) && (c != '\n')) {
		if (c == '0') {
			if (prev == '0') {
				prev = c = '1';
			} else {
				prev = c = '0';
			} 
			cout << c;
			if (prev == '0') {
				prev = c = '1';
			} else {
				prev = c = '0';
			} 
			cout << c; 
		} else {
			c = prev;
			cout << c;
			if (prev == '0') {
				prev = c = '1';
			} else {
				prev = c = '0';
			}
			cout << c;
		}
	}
	cout << endl;

	return 0;
}

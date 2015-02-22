#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char c;
	while ((c = getchar()) && (c != '\n')) {
		int k = c-'0';
		cout << (!k);
	}
	cout << endl;
}

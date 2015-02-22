#include <iostream>

using namespace std;

int fib(int n)
{
	int x;

	if (n == 0 ) {
		return 0;
	} else if (n == 1) {
		return 1;
	}

	cout << "   (finding for " << n << ")" << endl;
	x = fib(n - 1) + fib(n - 2);

	return x;
}

int main()
{
	for (int i = 0; i < 6; i++) {
		cout << "fib(" << i << ") = " << fib(i) << endl;
	}
getchar();
getchar();
	return 0;
}


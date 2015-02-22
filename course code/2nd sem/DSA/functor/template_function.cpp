#include <iostream>
#include <string>

using namespace std;

template<typename T1, typename T2>
T1 add(T1 x, T2 y)
{
	T1 z;
	z = x + (T1) y;
	return z;
}

int main()
{
	string s1 = "Hello ";
	string s2 = "World!";

	cout << add(5, 3) << endl;
	cout << add(5, 3.5) << endl;
	cout << add(5.5, 3) << endl;
	cout << add(5.2, 3.5) << endl;
	cout << add(s1, s2) << endl;

	return 0;
}


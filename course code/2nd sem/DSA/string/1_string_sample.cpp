#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1("Hello");

	cout << "s1.size() = " << s1.size() << endl;
	for (int i = 0; i < (int) s1.size(); i++) {
		cout << s1[i] << endl;
	}
	cout << endl;

	return 0;
}


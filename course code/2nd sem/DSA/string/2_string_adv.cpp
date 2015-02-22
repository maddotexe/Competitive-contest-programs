#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1("Hello");
	string s2("World!");

	cout << "s1.size() = " << s1.size() << endl;
	for (int i = 0; i < (int) s1.size(); i++) {
		cout << s1[i] << endl;
	}
	cout << endl;

	string s3;

	s3 = s1 + " " + s2;
	cout << "s3 = " << s3 << endl;

	cout << "s3.size() = " << s3.size() << endl;
	printf("My C-string is: %s\n", s3.c_str());

	return 0;
}


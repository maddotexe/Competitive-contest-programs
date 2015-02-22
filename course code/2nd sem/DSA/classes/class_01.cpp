#include <iostream>
#include <string>

using namespace std;

struct student {
	int age;
	string name;
};

int main()
{
	student st1;
	st1.age = 20;
	st1.name = "Vikalp";

	cout << st1.name << " " << st1.age << endl;

	return 0;
}


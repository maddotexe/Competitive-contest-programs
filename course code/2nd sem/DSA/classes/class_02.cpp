#include <iostream>
#include <string>

using namespace std;

struct student {
	int age;
	string name;

	void set_age(int x)
	{
		age = x;
	}
};

int main()
{
	student st1;
	st1.name = "Vikalp";

	st1.age = 20;
	cout << st1.name << " " << st1.age << endl;

	int t = 22;
	st1.set_age(t);

	cout << st1.name << " " << st1.age << endl;

	return 0;
}


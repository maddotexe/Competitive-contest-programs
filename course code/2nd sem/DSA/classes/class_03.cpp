#include <iostream>
#include <string>
#include <deque>

using namespace std;

struct student {
	int age;
	string name;

	student(int x)
	{
		age = x;
		cout << "Object born at age = " << age << endl;
	}

	void set_age(int x)
	{
		age = x;
	}

	~student()
	{
		cout << "Object destroyed" << endl;
	}
};

int main()
{
	student st1(20);
	st1.name = "Vikalp";

	cout << st1.name << " " << st1.age << endl;

	int t = 22;
	st1.set_age(t);

	cout << st1.name << " " << st1.age << endl;

	return 0;
}


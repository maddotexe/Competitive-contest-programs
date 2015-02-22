#include <iostream>
#include <string>

using namespace std;

struct student {
	int age;
	string name;

	student(int x)
	{
		age = x;
		cout << "Object born at age = " << age << endl;
	}

	student(string str, int x)
	{
		age = x;
		cout << str << " born at age = " << age << endl;
	}

	void get_age(int x)
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
	student st2("Maurice", 24);
	return 0;
}

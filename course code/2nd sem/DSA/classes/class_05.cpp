#include <iostream>
#include <string>

using namespace std;

struct student {
private:
	int age;

public:
	string name;

	void set_age(int x)
	{
		age = x;
	}

	int get_age()
	{
		return age++;
	}
};

int main()
{
	student st1;
	st1.name = "Vikalp";

	st1.set_age(20);
	
	cout << st1.name << " " << st1.get_age() << endl;
	cout << st1.name << " " << st1.get_age() << endl;
	cout << st1.name << " " << st1.get_age() << endl;

	return 0;
}


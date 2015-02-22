#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct student {
private:
	T age;

public:
	string name;

	void set_age(T x)
	{
		age = x;
	}

	T get_age()
	{
		return age++;
	}
};

int main()
{
	student<int> st1;
	st1.name = "Vikalp";

	st1.set_age(20);
	
	cout << st1.name << " " << st1.get_age() << endl;
	cout << st1.name << " " << st1.get_age() << endl;
	cout << st1.name << " " << st1.get_age() << endl;

	student<double> st2;
	st2.name = "Maurice";

	st2.set_age(20.25);
	
	cout << st2.name << " " << st2.get_age() << endl;
	cout << st2.name << " " << st2.get_age() << endl;
	cout << st2.name << " " << st2.get_age() << endl;
    getchar();
    getchar();
	return 0;
}


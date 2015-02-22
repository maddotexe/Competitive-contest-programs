#include <iostream>

using namespace std;

class C {
public:
	int n;

	C()
	{
		n = 0;
		cout << "Constructor: " << n << endl;
	}

	int operator()()
	{
		return n;
	}

	int operator()(int x)
	{
		n += x;
		return n;
	}

	~C()
	{
		cout << "Destructor: " << n << endl;
	}
};

int main()
{
	C ob;

	cout << ob() << endl;
	cout << ob(5) << endl;
	cout << ob(5) << endl;
	cout << ob() << endl;

	return 0;
}


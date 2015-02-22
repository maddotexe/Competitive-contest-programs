#include <iostream>
#include <string>

using namespace std;

template<typename T>
class C {
public:
	T z;

	C(T x, T y)
	{
		z = x + y;
	}
};

int main()
{
	C<int> ob_i(-10.1, 20.6);
	C<float> ob_f(-10.1, 20.6);
	C<string> ob_s("-10.1", "20.6");
	C<unsigned int> ob_u(-10.1, 20.6);

	cout << ob_i.z << endl;
	cout << ob_f.z << endl;
	cout << ob_s.z << endl;
	cout << ob_u.z << endl;

	return 0;
}


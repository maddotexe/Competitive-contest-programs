#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fp;
	
	fp.open("2^32.txt");
	long long int r = 1;
	for (int i = 0; i < 33; i++) {
		fp << r << ", ";
		r *= 2;
	}
	
	return 0;
}

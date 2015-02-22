#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char ch;
	fstream fp;
	fp.open("input1.txt");
	while (!fp.eof()) {
		fp.get(ch);
		cout << ch;
	}
	fp.close();
	cin >> ch;
	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int a[100][100];

int minm(int g, int b, int c)
{
	return min(g, min(b, c));
}

void func(string s1, string s2)
{
	int l1 = 0;
	int l2 = 0;
	int min = 9999;

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i] == s2[j]) {
				a[i][j] = minm(a[i-1][j-1], a[i][j-1] + 1, a[i-1][j] + 1);
			} else {
				a[i][j] = minm(a[i-1][j-1] + 2, a[i][j-1] + 1, a[i-1][j] + 1);
			}
		}
	}
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;
	for (int i = 0; i <= s1.length(); i++) {
		a[0][i] = i;
	}
	for (int i = 0; i <= s2.length(); i++) {
		a[i][0] = i;
	}

	func(s1, s2);

	cout << endl << a[s1.length()][s2.length()] << endl;
}

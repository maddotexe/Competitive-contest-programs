#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct student {
	int roll;
	float cgpa;
};

bool operator<(student st1, student st2)
{
	if (st1.cgpa > st2.cgpa) {
		return true;
	}

	return false;
}

int main()
{
	student st;
	vector<student> v;

	for (int i = 0; i < 10; i++) {
		st.roll = i;
		st.cgpa = (float) (rand() % 1000) / 100;
		v.push_back(st);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].roll << " " << v[i].cgpa << endl;
	}
	cout << endl;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].roll << " " << v[i].cgpa << endl;
	}
    getchar();
    getchar();
	return 0;
}


#include <iostream>
#include <list>

using namespace std;

void prt_list(list<int> lst)
{
	list<int>::iterator it;

	cout << "lst.size() = " << lst.size() << endl;
	for (it = lst.begin(); it != lst.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
}

int main()
{
	list<int> lst;
	list<int>::iterator it1;
	list<int>::iterator it2;

	for (int i = 0; i < 8; i++) {
		lst.push_back(i);
	}
	prt_list(lst);

	lst.pop_front();
	lst.pop_back();
	prt_list(lst);

	it1 = lst.begin();
	lst.erase(it1);
	prt_list(lst);

	it1 = lst.begin();
	it2 = lst.begin();
	advance(it1, 1);
	advance(it2, 3);
	lst.erase(it1, it2);
	prt_list(lst);
    getchar();
    getchar();
	return 0;
}


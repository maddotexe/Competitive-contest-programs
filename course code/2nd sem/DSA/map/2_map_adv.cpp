#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	string s;
	map<string, int> m;
	map<string, int>::iterator it;

	m.insert(pair<string, int>("One", 1));
	m.insert(pair<string, int>("Two", 2));
	m.insert(pair<string, int>("Three", 3));

	for (it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << " -> " << (*it).second << endl;
	}
	cout << endl;

	cout << m["Two"] << endl;

	s = "Two";
	if (m.count(s)) {
		cout << m[s] << endl;
	} else {
		cout << "No key " << s << endl;
	}

	s = "Four";
	if (m.count(s)) {
		cout << m[s] << endl;
	} else {
		cout << "No key " << s << endl;
	}

	return 0;
}


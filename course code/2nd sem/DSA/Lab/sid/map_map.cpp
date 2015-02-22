#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	map<string, map<string, int> > mm;
	map<string, int> m;
	string name;
	string jamat;
	int mks;
	map<string, map<string, int> > :: iterator it;
	map<string, int> :: iterator ece;

	for (int j = 0; j < 2; j++) {
		getline(cin, name);
		cin >> mks;
		getchar();
		m.insert(pair<string, int> (name, mks));
	}
	printf("enter jamat\n");
	for (int i = 0; i < 2; i++) {
		getline(cin, jamat);
		mm.insert(pair<string, map<string, int> >(jamat, m));
	}

	for (it = mm.begin(); it != mm.end(); it++) {
		cout << it->first << " = "<< endl;
		for (ece = (*it).second.begin(); ece != (*it).second.end(); ece++) {
			cout << ece->first <<" = " << ece->second << endl;
		}
	}
	
	return 0;
}

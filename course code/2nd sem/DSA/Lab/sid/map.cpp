#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main()
{
	
	map<int, string> m;
	map<int, string>::iterator it;
	int i;
	i = 0;
	int ch;
	do {
		cout<<"press 1 to enter a new value\n";
		cout<<"press 2 to delete a value\n";
		cout<<"press 3 to find a given value\n";
		cout<<"press 4 to display all the contents\n";
		cout<<"press 5 to exit\n";
		cout<<"enter your choice\n";
		cin >> ch;
	
		switch(ch) {
		
			case 1:
			{	
				int x;
				string s;
				i++;
				cout<<"enter "<< i << "value\n";
				cin >> x;
				getchar();
				getline(cin, s);
				m.insert(pair<int, string>(x, s));
				break;
			
			}
			
			case 2:
			{	
				int pos;
				cout<<"enter the position you want to delete\n";
				cin >> pos;
				int s = 1;
				for(it = m.begin(); s != pos; it++, s++); 
				m.erase(it);
				break;
			}
			case 3:
			{	
				int v;
				cout << "enter the value to be found\n";
				cin >> v;
				it = m.begin();
				for(it = m.begin(); it != m.end(); it++) {
					if(v == (*it).first) {
						cout<< "value found at key "<< (*it).second;
						break;
					}
			
				}
			}
			case 4:
			{	
				cout<<endl;
				for(it = m.begin(); it != m.end(); it++) {
					cout<<(*it).first << " " << (*it).second<< endl;
		
				}
			break;
			}
			case 5:
			{
				cout<<"Quitting Program"<<endl;
				break;
			}
			
			default :
				{
					cout<<"WRONG CHOICE enter valid choice\n";
			}
		}
		
		}while(ch != 5);
	
	return 0;
} 

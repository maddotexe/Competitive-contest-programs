#include <iostream> 
#include <list>

using namespace std;

int main()
{
        list<int> v;
	list<int>::iterator it;
        it = v.begin();
	int ch = 0;
	int i = 0;
        while (ch != 5) {
        cout<<"\nPress 1 to enter an element"<<endl;
        cout<<"Press 2 to delete an element"<<endl;
        cout<<"Press 3 to find an element"<<endl;
        cout<<"Press 4 to print all the elements"<<endl;
        cout<<"Press 5 to exit\n"<<endl;
        cin>>ch;

                if (ch == 1) {
			cout<<"Enter the element"<<endl;
                        int x;
			cin>>x;	
                       	v.push_back(x);
                        i++;
                        
                }

                else if (ch == 2) {
                        if (i > 0) {
                                cout<<"Element Deleted"<<endl;
                                v.pop_back();
				i--;
                        }
                        else {
                                cout<<"There is no element in the vector"<<endl;
                        }
                }

                else if (ch == 3) {
                        int j = 0;
                      	int x;
                        int c = 0;
                        cout<<"enter the element to be found"<<endl;
                        cin>>x;
			
                        
			for (it = v.begin(); it != v.end(); it++,j++) {
                                if (x == *it) {
                                        cout<<"Element found at"<<j+1<<"th position";
                                        c++;
                                }
                        }
                        
			if (c == 0) {
                                cout<<"no such element found"<<endl;
                        }
                }
	
		else if(ch == 4) {
                        int j;
                        if (i == 0) {
                                cout<<"Koi element hai hi nhi"<<endl;
                        }
                        else {
                                for (it = v.begin();it != v.end();it++) {
                                        cout<<*it<<endl;
                     		}
                        }
                }

        }

        return 0;

}


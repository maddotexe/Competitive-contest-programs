#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    queue<int> q;
    
    cout << "Enter size: ";
    cin >> n;
    cout << "1. Push\t2. pop\t3. Exit\n";
    
    while (1) {
        cout << "enter choice : ";
        cin >> k;
        if (k == 3) {
            return 0;
        }
        switch(k) {
            case 1: if (q.size() < n) {
            		if (q.size() == 0) {
            		    cout << "processor wakes up\n";
            		}
            	            cout << "Enter number : ";
            	            cin >> k;
                	        q.push(k);
              	        } else {
                 	       cout << "queue full\n";
                    	}
                   	 break;
                    
            case 2: if (q.empty()) {
                        cout << "queue empty\n";
                    } else {
                        cout << "No. popped : " << q.front() << endl;
                        q.pop();
                        if (q.empty()) {
                        	cout << "processor sleeps\n";
                        }
                    }
                    break;
                    
            default: break;
        }
    }
    
    return 0;
}

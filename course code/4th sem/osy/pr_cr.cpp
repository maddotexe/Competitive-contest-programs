#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    queue<int> q;
    
    cout << "Enter size: ";
    cin >> n;
    cout << "1. Producer\t2. Consumer\t3. Exit\n";
    
    while (1) {
        cout << "enter choice : ";
        cin >> k;
        if (k == 3) {
            return 0;
        }
        switch(k) {
            case 1: if (q.size() < n) {
                        cout << "Enter process : ";
                        cin >> k;
                        q.push(k);
                    } else {
                        cout << "Overflow\n";
                    }
                    break;
                    
            case 2: if (q.empty()) {
                        cout << "Underflow\n";
                    } else {
                        cout << "Process No. : " << q.front() << endl;
                        q.pop();
                    }
                    break;
                    
            default: break;
        }
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void barber_sleeps()
{
	cout << "barber is still sleeping" << endl;
}

void awake_barber()
{
	cout << "The barber is being awaked by customer" << endl;
	cout << "Barber awake!" << endl;
}

int main()
{
	int n;
	int k;
	int p = 0;
	queue<int > q;
	
	cout << "Enter the no of processes : ";
	cin >> n;
	
	while (1) {
		cout << "Press : " << endl;
		cout << "1. new process 2. barber_work 3. exit" << endl;
		cin >> k;
		
		if (k == 1) {
			if (p == n) {
				cout << "overflow :" << endl;
			} else {
				if (p == 0) {
					awake_barber();
				}
				q.push(p++);
			}
		} else if (k == 2) {
			if (p == 0) {
				barber_sleeps();
			} else {
				cout << "barber works : " << q.front() << endl;
				q.pop();
				p --;
			}
		} else if (k == 3) {
			cout << "exiting press any key : " << endl;
			cin >> k;
			return 0;
		}
		if (p == 0) {
			cout << "Our Barber is sleeping!" << endl;
		}
	}
	
	return 0;
}			

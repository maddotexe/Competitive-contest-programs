#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

queue<int> q;
int n;
int p;
void consume() {
	if (q.size() == 0) {
		cout << "underflow\n";
		return;
	}
	cout << q.front() << " popped\n";
	q.pop();
	if (q.size() == 0) {
		cout << "consumer sleeps\n";
	}
	if (q.size() == n - 1) {
		cout << "producer wakesup\n";
	}
}


void produce()
{
	
	if (q.size() == n) {
		cout << "overflow\n";
		return;
	}
	if (q.size() == 0) {
		cout << "producer wakes up\nconsumer wakes up\n";
	}
	int y = rand() % 20;
	q.push(y);
	cout << "process produce : " << y;
	cout << endl;
	if (q.size() == n) {
		cout << "producer sleeps\n";
	}
}

int main()
{
	srand(time(NULL));
	cin >> n;
	for (int i = 1; i < 20; i++) {
		p = rand() % 2 + 1;
	
		if (p == 1) 
			consume();
		else 
			produce();
	}
	
	return 0;
}

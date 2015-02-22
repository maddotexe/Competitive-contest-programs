#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

void stall()
{
	for (int i = 0; i < 24000; i++) {
		for (int j = 0; j < 10000; j++) {

		}
	}
}

int mproducer = 0;
int mconsumer = 0;
volatile bool s1;
volatile bool s2;
int list_size = 5;
volatile int p = 0;
list<int> lst;

void sleep_producer()
{
	mproducer = 1;
}

void wake_producer()
{
	mproducer = 0;
}

void sleep_consumer()
{
	mconsumer = 1;
}

void wake_consumer()
{
	mconsumer = 0;
}

void setsize_buffer(int n)
{
	list_size = n;
}

void controlproducer()
{
	p = lst.size();
	if (p == list_size) {
		s1 = false;
		sleep_producer();
	} else {
		s1 = true;
		wake_producer();
	}
}


void controlconsumer()
{
	p = lst.size();
	if (p == 0) {
		s2 = false;
		sleep_consumer();
	} else {
		s2 = true;
		wake_consumer();
	}
}

void producer()
{
	if (s1 == true) {
		lst.push_back(1);
		p = lst.size();
		cout << "producing" << "     " << "units left : " << p << endl;
	} else {
		cout << "overflow, can't produce" << endl;
	}
}

void consumer()
{
	if (s2 == true) {
		lst.pop_front();
		p = lst.size();
		cout << "consuming" << "     " << "units left : " << p << endl;
	} else {
		cout << "underflow, can't consume" << endl;
	}
}

void run()
{
	int t = 0;
	int m = 10;
	while (true) {
//		stall();
		cin >> t;
//		t = rand();
		cout << endl;
		if (t % 2 == 1) {
			if (mproducer == 1) {
				t++;
			}
			wake_producer();
		} else {
			if (mconsumer == 1) {
				t++;
			}
			wake_consumer();
		}
		if (t % 2 == 1) {
			cout << "PRODUCER PRODUCING" << endl;
			controlproducer();
			producer();
		} else {
			cout << "CONSUMER CONSUMING" << endl;
			controlconsumer();
			consumer();
		}
	}
}

int main()
{
	cout << "------ enter : SIZE OF BUFFER -------" << endl;
	int n;
	cin >> n;
	setsize_buffer(n);
	cout << endl;
	run();

	return 0;
}

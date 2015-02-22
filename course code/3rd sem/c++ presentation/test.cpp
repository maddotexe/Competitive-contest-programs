#include <iostream>
#include <queue>
#include <functional>
 
using namespace std;
 
struct Process
{
	int priority;
 
	Process(int p) {
		priority = p;
	}
 
	friend bool operator <(const Process &p1, const Process &p2) {
		return p1.priority < p2.priority;
	}
};
 
int main()
{
	priority_queue<Process> pq;
 
	pq.push( Process(3) );
	pq.push( Process(4) );
	pq.push( Process(2) );
	pq.push( Process(1) );
 
	while ( pq.size() ) {
		cout << pq.top().priority << endl;
		pq.pop();
	}
	int  n;
 cin >> n;
	return 0;
}
 

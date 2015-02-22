#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

void consumer(queue<int> &q, int x, queue<int> &p_q)
{
	if(q.size() == 0){
		cout << "buffer is empty consumer is sleep"<< endl;
	}else{
		int x = q.front();
		q.pop();
		cout << "consuming " << x << endl;
	}
}

void producer(queue<int> &q, int x, queue<int> &p_q)
{
	if(q.size() <= x-1){
		cout << "q size " << q.size()+1 <<endl;
		int y=p_q.front();
		q.push(y);
		p_q.pop();
	}else{
		cout << "OVERFLOW buffer is full producer is sleep calling consumer" << endl;	
		consumer(q, x, p_q);
	}
}
	


int main()
{
	queue<int> q,p_q;
	int x,v;
	int s = 0;
	cout << "enter buffer size" << endl;
	cin >> x;
	
	int p;
	
		int t = 1;
	cout << "both consumer and producer are awake" << endl;
	cout << "enter 1: to produce \nenter 2: to consume\nenter 3: to exit" << endl;
	
	while(1){
		cin >> p;
		if(p == 1){
			cout << "producer is producing"<< endl;
			cout << "enter process number : ";
			cin >> v;
			p_q.push(v);
			producer(q,x,p_q);
			queue <int> q1 (q);
			for (int i = s; i < t; i++) {
				cout << q1.front() << endl;
				q1.pop();
				
			}
			t++;
			
		}
	
		if(p == 2){
			cout << "consumer is consuming" << endl;
			consumer(q,x,p_q);
			s++;
			queue <int> q1 (q);
			for (int i = s; i < t; i++) {
				cout << q1.front() << endl;
				q1.pop();
				
			}
			
		}
	
		if(p == 3){
			break;
		}
	}
}


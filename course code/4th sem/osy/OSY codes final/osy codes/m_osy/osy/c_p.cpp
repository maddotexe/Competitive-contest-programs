#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
void producer(queue<int> &q, int x, queue<int> &p_q);
void consumer(queue<int> &q, int x, queue<int> p_q)
{
	if(q.size() == 0){
		cout << "buffer is empty consumer is sleep"<< endl;
		cout << "producer is awake" << endl;
		producer(q, x, p_q);
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
		cout << "buffer is full producer is sleep" << endl;
		cout << "consumer awake" << endl;		
		consumer(q, x, p_q);
	}
}
	

/*void consumer(queue<int> &q, int x, queue<int> p_q)
{
	if(q.size() == 0){
		cout << "buffer is empty consumer is sleep"<< endl;
		cout << "producer is awake" << endl;
		producer(q, x, p_q);
	}else{
		int x = q.front();
		q.pop();
		cout << "consuming " << x << endl;
	}
}*/

int main()
{
	queue<int> q,p_q;
	int x,v;
	cout << "enter buffer size" << endl;
	cin >> x;
	
	int cases;
	cout << "both consumer and producer are sleeping" << endl;
	cout << "enter 1: to produce \t enter2 : to consume\t enter 3: to exit" << endl;
	
	while(1){
		cin >> cases;
		if(cases == 1){
			cout << "producer is producing"<< endl;
			cin >> v;
			p_q.push(v);
			producer(q,x,p_q);
		}
	
		if(cases == 2){
			cout << "consumer is consuming" << endl;
			consumer(q,x,p_q);
		}
	
		if(cases == 3){
			break;
		}
	}
}


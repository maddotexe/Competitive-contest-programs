#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <exception>
#include <queue>
#include <vector>

#define RET(a) if (a) return

using namespace std;

struct nod {
	int prob;
	string s;
	struct nod *left;
	struct nod *right;
};

typedef struct nod node;

struct nod1 {
	node *pointer;
};

typedef struct nod1 node1;

bool operator<(node1 a, node1 b)
{
	if (a.pointer -> prob > b.pointer -> prob) {
		return true;
	}

	return false;
}

map<string, int> m;
priority_queue<node1> pq;
vector<string> v;

void print(node *head, string &s, bool &flag, string findS)
{
	RET(flag);
	if (! head) {
		return;
	}

	if (head -> s == findS) {
		flag = true;
		return;
	} 
	s += "0";

	RET(flag);
	print(head -> left, s, flag, findS);
	RET(flag);

	string s2 = s.substr(0, s.size()-1);
	s = s2;
	s += "1";
	
	RET(flag);
	print(head -> right, s, flag, findS);
	RET(flag);

	s2 = s.substr(0, s.size()-1);
	s = s2;
}

int main()
{
	ifstream in("huffman_file.txt");
	if (! in.good()) {
		cout << "Error in opening file" << endl;
	}
	
	string s1 = "";
	
	while (in >> s1) {
		v.push_back(s1);
		m[s1]++;
	}

	int m_sz = m.size();
	node *a[m_sz];
	int j = 0;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
		a[j] = new node();
		a[j] -> prob = (*it).second;
		a[j] -> s = (*it).first;
		a[j] -> left = a[j] -> right = NULL;
		node1 toPush;
		toPush.pointer = a[j];
		pq.push(toPush);
	}
	
	while (true) {
		node1 del1 = pq.top();
		pq.pop();
		node1 del2 = pq.top();
		pq.pop();

		node *toInsert = new node();
		toInsert -> prob = del1.pointer -> prob + del2.pointer -> prob;
		toInsert -> s = del1.pointer -> s + del2.pointer -> s;
		toInsert -> left = del1.pointer;
		toInsert -> right = del2.pointer;

		node1 inserted;
		inserted.pointer = toInsert;
		pq.push(inserted);
		if (pq.size() == 1) {
			break;
		}
	}
	node1 headPointer = pq.top();
	pq.pop();
	node *head = headPointer.pointer;
	in.close();
	ofstream out("huffmanOutput.txt");
	int v_sz = v.size();
	for (int i = 0; i < v_sz; i++) {
		out << v[i] << " ";
	}
	out << endl;
	for (int i = 0; i < v_sz; i++) {
		string s = "";
		string findS = v[i];
		bool flag = false;
		print(head, s, flag, findS);
		out << s << " ";
	}
	out << endl;

	return 0;
}

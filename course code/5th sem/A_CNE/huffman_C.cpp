#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <exception>
#include <queue>
#include <vector>

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
	if (flag) {
		return;
	}
	if (! head) {
		return;
	}

//	cout << head -> s << " " << findS << "  " << s << endl;
	if (head -> s == findS) {
//		cout << "equal = " << head -> s << " " << findS << endl;
		flag = true;
		return;
	} else {
//		cout << "not equal = " << head -> s << "  " << findS << endl;
	}
//	cout << head -> s << " " << head -> prob << endl;
	s += "0";
	if (flag) {
		return;
	}
	print(head -> left, s, flag, findS);
	if (flag) {
		return;
	}
	string s2 = s.substr(0, s.size()-1);
	s = s2;
	s += "1";
	if (flag) {
		return;
	}
	print(head -> right, s, flag, findS);
	if (flag) {
		return;
	}
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

//	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
//		cout << (*it).first << " -> " << (*it).second << endl;
//	}

	int m_sz = m.size();
	node *a[m_sz];
	int j = 0;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
		a[j] = new node();
		a[j] -> prob = (*it).second;
		a[j] -> s = (*it).first;
//		cout << a[j] -> s << endl;
		a[j] -> left = NULL;
		a[j] -> right = NULL;
		node1 toPush;
		toPush.pointer = a[j];
		pq.push(toPush);
	}
	
	while (true) {
//		cout << pq.size() << " ";
		node1 del1 = pq.top();
//		cout << del1.pointer -> s << "  " << del1.pointer -> prob << endl;
		pq.pop();
		node1 del2 = pq.top();
		pq.pop();

		node *toInsert = new node();
		toInsert -> prob = del1.pointer -> prob + del2.pointer -> prob;
		toInsert -> s = del1.pointer -> s + del2.pointer -> s;
//		cout << del1.pointer -> s << endl;
//		cout << del2.pointer -> s << endl;
		toInsert -> left = del1.pointer;
		toInsert -> right = del2.pointer;

		node1 inserted;
		inserted.pointer = toInsert;
//		cout << inserted.pointer -> left -> s << endl;
		pq.push(inserted);
		if (pq.size() == 1) {
			break;
		}
	}
	node1 headPointer = pq.top();
	pq.pop();
	node *head = headPointer.pointer;
//	cout << head -> prob << endl;
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
//		cout << findS;
		bool flag = false;
		print(head, s, flag, findS);
//		cout << " to print " << s << endl;
		out << s << " ";
	}
	out << endl;

	return 0;
}

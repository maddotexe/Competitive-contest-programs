#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	node* parent;

	node () {
		left = parent = right = NULL;
	}
};

class heap {
	public:
	node* add (node* , int , int , vector<int> );
	void print (node* );

	node* root;
	int size;

	public:
	heap () {
		root = NULL;
		size = 1;
	}

	void heapify (node* );
	void dele1(node *, vector<int> , int );
	void insert (int );
	void print ();
	void dele ();
	void heapify_down(node *);

};

void heap::heapify (node* root)
{
	if (root->parent == NULL) {
		return;
	}

	if (root->data < root->parent->data) {
		swap(root->data, root->parent->data);
		heapify (root->parent);
	} else {
		return;
	}
}

void heap::print (node* root)
{
	if (root == NULL) {
		return;
	}

	print (root->left);
	cout << root->data << " ";
	if (root->parent != NULL) {
		cout << "father = " << root->parent->data << endl;
	} else {
		cout << "max node\n";
	}
	print (root->right);
}

void heap::print ()
{
	print(root);
}

node* heap::add (node* root, int info, int n, vector<int> b)
{
	if (root == NULL) {
		root = new node;
		root->data = info;
		return root;
	}


	if (!b[n]) {
		root->left = add (root->left, info, n - 1, b);
		root->left->parent = root;
		heapify(root->left);
	} else {
		root->right = add (root->right, info, n - 1, b);
		root->right->parent = root;
		heapify (root->right);
	}

	return root;
}

void heap::insert (int info)
{
	vector <int> v;
	int l = size;
	int i = 0;
	while (l > 1) {
		v.push_back(l % 2);
		l /= 2;
		i++;
	}

	root = add (root, info, v.size() - 1, v);
	size++;
	v.clear();
}

void heap::heapify_down(node * root) {
	if (root == NULL) {
		return ;
	}
 	if (root->left != NULL && root->right == NULL) {
 		if (root->left->data < root->data) {
   		   swap(root->data, root->left->data);
	 	   heapify_down(root->left);
		 } else {
		 	return;
		 }
	 } else {
	   	if (root->right->data < root->left->data) {
     		   swap(root->data, root->right->data);
		   heapify_down(root->right);
		} else {
  		   swap(root->data, root->left->data);
	 	   heapify_down(root->left);
                }
	 }
	 
}

void dele1(node * root, vector<int> v, int n) {
	int i = n;
	node * p = root;
	while ( i >= 0) {
	if (!v[n]) {
		p = p->left;
	} else {
		p = p->right;
	}
	i--;
	}
	if(!v[n-1]) {
		p->data = p->parent->left->data;
		p->parent->left = NULL;
	} else {
		p->data = p->parent->right->data;
		p->parent->right = NULL;
	}
}
void heap::dele() {
	
	vector <int> v;
	int l = size;
	int i = 0;
	while (l > 1) {
		v.push_back(l % 2);
		l /= 2;
		i++;
	}
	i = v.size() - 1;
	node * p = root;
	while ( i >= 0) {
	if (!v[i]) {
		p = p->left;
	} else {
		p = p->right;
	}
	i--;
	}
	swap(root->data, p->data);
	if(p->parent->right != NULL) {
	//	p->data = p->parent->right->data;
		p->parent->right = NULL;
		
	} else {
	//	p->data = p->parent->left->data;
		p->parent->left = NULL;
		
	}
	heapify_down(root);
	size--;
	print(root);
}
int main ()
{
	heap h;
	for (int i = 0 ; i < 5; i++) {
		h.insert (i + 1);
	}
	h.size--;
	h.print ();
	cout << endl;
	
	h.dele();
	

	return 0;
}


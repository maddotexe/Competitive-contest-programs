#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
struct node {
	T data;
	node<T> *left;
	node<T> *right;
};

template<typename T>
node<T> *make_node(T data)
{
	node<T> *ptr = new node<T>;

	ptr->data = data;
	ptr->left = ptr->right = NULL;

	return ptr;
}

template<typename T>
void insert(node<T> *ptr, T data, string b, int k)
{
	T tmp;

	if (b[k] == '1') {
		if (ptr->right == NULL) {
			ptr->right = make_node(data);
		} else {
			insert(ptr->right, data, b, k - 1);
		}
		
		if (ptr->data < ptr->right->data) {
			swap(ptr->data , ptr->right->data);
		}
	} else {
		if (ptr->left == NULL) {
			ptr->left = make_node(data);
		} else {
			insert(ptr->left, data, b, k - 1);
		}

		if (ptr->data < ptr->left->data) {
			swap(ptr->data, ptr->left->data);
		}
	}
}

string to_bool(int x)
{
	string s;

	while (x != 1) {
		s += x % 2 + '0';
		x /= 2;
	}

	return s;
}

template<typename T>
T val(node<T> *ptr, string s)
{
	T x;

	for (int i = s.size() - 1; i > 0; i--) {
		if (s[i] == '0') {
			ptr = ptr->left;
		} else {
			ptr = ptr->right;
		}
	}

	if (s[0] == '0') {
		x = ptr->left->data;
		ptr->left = NULL;
	} else {
		x = ptr->right->data;
		ptr->right = NULL;
	}

	return x;
}

template<typename T>
void heapfy(node<T> *ptr)
{
	T l, r;
	//l = r = -999;

	if (ptr->left != NULL) {
		l = ptr->left->data;
	}
	if (ptr->right != NULL) {
		r = ptr->right->data;
	}

	if (l >= r && l > ptr->data) {
		swap(ptr->data, ptr->left->data);
		heapfy(ptr->left);
	} else if (r >= l && r > ptr->data) {
		swap(ptr->data, ptr->right->data);
		heapfy(ptr->right);
	}
}


template<typename T>
class max_heap {
	public:
	node<T> *root;
	int n;

	max_heap()
	{
		root = NULL;
		n = 0;
	}

	void push(T data)
	{
		n++;
		if (n == 1) {
			root = make_node(data);
		} else {
			string b;
			b = to_bool(n);
			insert(root, data, b, b.size() - 1);
		}
	}

	T pop()
	{
		T x = root->data;

		if (n == 1) {
			root = NULL;
		} else {
			string b = to_bool(n);

			root->data = val(root, b);
			heapfy(root);
		}
		n--;

		return x;
	}
	T top() {
		return root->data;
	}
};

template<typename T>
void inorder(node<T> *ptr)
{
	if (ptr != NULL) {
		inorder(ptr->left);
		cout << ptr->data << " ";
		inorder(ptr->right);
	}
}

/*int main()
{
	max_heap<int> h;
	int x, n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		h.push(x);
	}
	
	cout << "Output:" << endl;
	for (int i = 0; i < n; i++) {
		inorder(h.root);
		cout << endl << "Max Value = " << h.pop() << endl;
	}

	return 0;
}*/

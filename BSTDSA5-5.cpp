// TreeDSA-5-5.cpp : 

#include <iostream>
#include <Queue>
#define template t
using namespace std;
class binarySearchTree {
private:
	struct node
	{
		int val;
		node* left;
		node* right;
	};
	node* root = NULL;
	// root left right
	void preOrder(node* p) {
		// the base case  when i stop
		if (p == nullptr)return;
		//transition what i do 
		cout << p->val << " ";
		preOrder(p->left);
		preOrder(p->right);
	}
	// left right root
	void postOrder(node* p) {
		// the base case 
		if (p == nullptr)return;
		// trasnsition 
		postOrder(p->left);
		postOrder(p->right);
		cout << p->val << " ";
	}

	// left root right 
	void inOrder(node* p) {
		// the base case 
		if (p == nullptr)return;
		//transition
		inOrder(p->left);
		cout << p->val << " ";
		inOrder(p->right);
	}
	void levelOrder(node* root) {
		if (root == nullptr)return;
		queue<node*>q;
		q.push(root);
		while (!q.empty()) {
			node* cur = q.front();
			cout << cur->val << " ";
			if (cur->left)q.push(cur->left);
			if (cur->right)q.push(cur->right);
			q.pop();
		}
	}
public:
	void displyIn() {
		inOrder(root);
		cout << endl;
	}
	void displyPost() {
		postOrder(root);
		cout << endl;
	}
	void displyLevel() {
		levelOrder(root);
		cout << endl;
	}
	void displyPre() {
		preOrder(root);
		cout << endl;
	}
	
	bool isEmpty() {
		return root == NULL;
	}
	bool searchRec(node* p, int val) {
		//base case
		if (!p)return false;
		if (p->val == val)return true;
		//transition
		if (val > p->val) {
			searchRec(p->right, val);
		}
		else searchRec(p->left, val);
		
	}
	bool search(node* p, int val) {
		while (p) {
			if (p->val == val)return true;
			if (val > p->val) p = p->right;
			else p = p->left;
		}
		return false;
	}

	void insert(int data) {
		node* cur = root;
		node* parent = nullptr;
		node* nn = new node;
		nn->val = data;
		nn->left = NULL;
		nn->right = NULL;
		if (root == NULL) {
			root = nn;
			return;
		}
		while (cur) {
			parent = cur;
			if (cur->val == data) {
				cout << "this node is already exist and duplicate is not allowed\n";
				return;
			}
			else if (cur->val < data)cur = cur->right;
			else cur = cur->left;
		}
		if (parent->val < data)parent->right = nn;
		else parent->left = nn;
	}
	int hight(node* p) {
		
		//base case 
		if (!p)return -1;
		//transition
		int h = max(hight(p->left), hight(p->right))+1;
		return h;
	}
	int max(int x,int y) {
		if (x > y)return x;
		return y;
	}

	int cntNode(node*p) {
		//base case
		if (!p)return 0;
		//transition 
		int cnt = 1 + cntNode(p->left) + cntNode(p->right);//this plus one for include the cur node
		return cnt;
	}
	int cntLeaves(node*p) {
		// base caase
		if (!p)return 0;
		if (!p->right && !p->left)return 1;
		//transition
		int cnt = cntLeaves(p->right) + cntLeaves(p->left);
		return cnt;
	}
	void dltHelper(int val) {
		if (root == nullptr) {
			cout << "tree is empty\n";
			return;
		}
		if (root->val == val) {
			dltFromTree(root);
			return;
		}
		//else we search about this node 
		node* parent = root;
		node* cur;
		if (root->val < val) {
			cur = root->right;
		}
		else cur = root->left;
		while (cur) {
			if (cur->val == val) {
				break;
			}
			parent = cur;
			if (cur->val < val) {
				cur = cur->right;
			}
			else cur = cur->left;
		}
		if (cur == NULL) {
			cout << "this node doesn't exist in this tree\n";
			return;
		}
		//cur=> dlt node 
		//parent=> parent to dlt node 
		else if (val > parent->val) dltFromTree(parent->right);
		else dltFromTree(parent->left);
	}
	void dltFromTree(node*& p) {
		node* parent;
		node* cur;
		node* temp;
		// case doesn't have any child (leaf)
		if (!p->left && !p->right) {
			temp = p;
			p = NULL;
			delete temp;
			return;
		}
		// case this node has one child and it on the right
		if (!p->left) {
			temp = p;
			p = p->right;
			delete temp;
			return;
		}
		// case this node has one child and it on the left
		if (!p->right) {
			temp = p;
			p = p->left;
			delete temp;
			return;
		}
		// case node has two children we raplace it with it's predeccesor (the max on the left subtree)
		cur = p->left;
		parent = p;
		while (cur->right) {
			parent = cur;
			cur = cur->right;
		}
		// now the cur stop on the max val in left subtree
		p->val = cur->val;
		if (parent == p) {
			p->left = NULL;
		}
		else parent->right = NULL;

		delete cur;
		// case node has two children we raplace it with it's succcesor (the min on the right sub tree)

	}
	int getMax() {
		if (isEmpty()) {
			cout << "empty tree\n";
			return -1;
		}
		node* cur = root;
		while (cur->right) {
			cur = cur->right;
		}
		return cur->val;
	}
	int getMin() {
		if (isEmpty()) {
			cout << "empty tree\n";
			return -1;
		}
		node* cur = root;
		while (cur->left) {
			cur = cur->left;
		}
		return cur->val;
	}
};
int main()
{
	binarySearchTree BST;
	
	BST.insert(5);
	BST.insert(1);
	BST.insert(6);
	BST.insert(0);
	BST.insert(4);
	BST.insert(2);
	BST.displyPost();
	BST.dltHelper(0);
	BST.displyPost();
	cout << BST.getMin();
}

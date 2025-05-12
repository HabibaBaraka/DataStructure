// AVLTree.cpp 
// the real note you must be noted it << The root must be the median of this tree "in every sub tree">>
#include <iostream>
using namespace std;
class AVLTree {
private:
	struct node {
		node* left;
		node* right;
		
		int val;
		int hight=0;
	};
	
public:
	node* root = NULL;
	int hight(node* n) {
		if (!n)return 0;
		return n->hight;
	}
	int getBalance(node* n) {
		if (!n)return 0;
		return (hight(n->left) - hight(n->right));
	}
	void updateHight(node* &n) {
		n->hight= 1 + max(hight(n->left), hight(n->right));
	}
	node* insertBST(node* cur, int val) {
		if (!cur) {
			
			return new node{ nullptr,nullptr,val,0 };
		}
		else if (val > cur->val) {
			cur->right=insertBST(cur->right, val);
		}
		else if (val < cur->val) {
			cur->left=insertBST(cur->left, val);
		}
		return cur;
	}
	node* rightRotation(node* p) {
		node* x = p->left;
		node* affectSubTree = x->right;

		x->right = p;
		p->left = affectSubTree;

			//updateHight
			x->hight = 1 + max(hight(x->left), hight(x->right));
			p->hight = 1 + max(hight(p->left), hight(p->right));

			return x;
	}
	node* leftRotation(node* p) {
		node* x = p->right;
		node* affectSubTree = x->left;

		x->left = p;
		p->right = affectSubTree;

		//updateHight
		x->hight = 1 + max(hight(x->left), hight(x->right));
		p->hight = 1 + max(hight(p->left), hight(p->right));

		return x;
	}

	node* balanceTree(node* cur, int val, int b) {
		// case one LL
		if (b > 1 && val < cur->left->val) {
			return rightRotation(cur);
		}
		// case two RR
		if (b < -1 && val>cur->right->val) {
		return 	leftRotation(cur);
		}
		// case three LR
		if (b > 1 && val > cur->left->val) {
			cur->left = rightRotation(cur->left);
			return leftRotation(cur);
		}
		// case four RL
		if (b < -1 && val < cur->right->val) {
			cur->right = leftRotation(cur->right);
			return rightRotation(cur);
		}
		return cur;
	}
	node* insert(node*n,int val) {
		
		n = insertBST(n, val);// this fun  after standered insert return the top of the stack and apply this op until it empty
		updateHight(n);
		int balance = getBalance(n);
		return balanceTree(n, val, balance);

	}
	void inSert(int val) {
		root = insert(root, val);
	}
	void dltHelper(node*&p,int val) {
		//  base case 
		if (!p)return;
		//  transition what I do
		if (p->val < val) {
			dltHelper(p->right, val);
		}
		else if (p->val > val) {
			dltHelper(p->left, val);
		}
		else {
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
		}
		updateHight(p);
		int balance = getBalance(p);
		 balanceTree(p, val, balance);
	}

node* searchRec(node* p, int val) {
	//base case
	if (!p)return nullptr;
	if (p->val >= val)return p;
	//transition
	if (val > p->val) {
		searchRec(p->right, val);
	}
	else searchRec(p->left, val);

}
int lower_bound(int val) {
	node* n = searchRec(root, val);
	if (n)return n->val;
	else return -1;
}
node* search(node* p, int val) {
	//base case
	if (!p)return nullptr;
	if (p->val >= val) { if(p->val>val)return p; }
	//transition
		search(p->right, val);
}
int upper_bound(int val) {
	node* n = search(root, val);
	if (n)return n->val;
	else return -1;
}
	
	void preOrder(node* root) {
		if (root != nullptr) {
			cout << root->val << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}
};

int main() {
	AVLTree tree;

	// Insert values
	tree.inSert(10);
	tree.inSert(20);
	tree.inSert(30);
	tree.inSert(40);
	
	// Preorder traversal
	cout << "Preorder traversal: ";
	tree.preOrder(tree.root);
	cout << endl;

	// Delete a value
	tree.dltHelper(tree.root, 10);
	cout << tree.root->val << "\n";
	// Preorder traversal after deletion
	cout << "Preorder traversal after deletion: ";
	tree.preOrder(tree.root);
	cout << endl;
	
	return 0;
}

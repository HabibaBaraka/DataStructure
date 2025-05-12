// AVLTree.cpp 
// the real note you must be noted it << The root must be the median of this tree "in every sub tree">>
#include <iostream>
using namespace std;
class AVLTree {
private:
	struct node {
		node* left;
		node* right;
		
		string val;
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
	node* insertBST(node* cur, string val) {
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

	node* balanceTree(node* cur, string val, int b) {
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
	node* insert(node*n,string val) {
		
		n = insertBST(n, val);// this fun  after standered insert return the top of the stack and apply this op until it empty
		updateHight(n);
		int balance = getBalance(n);
		return balanceTree(n, val, balance);

	}
	void inSert(string val) {
		root = insert(root, val);
	}
	
	
	void preOrder(node* root) {
		if (root != nullptr) {
			cout << root->val << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}
	bool searchRec(node* p, string val) {
		
		//base case
		if (!p)return 0;
		if (p->val == val)return 1;
		//transition
		if (val > p->val) {
			return searchRec(p->right, val);
		}
		else return searchRec(p->left, val);
	}
	bool searchPre(node* p, string val) {
		//base case
		if (!p)return 0;
		if (p->val.find(val)==0)return 1;
		//transition
		if (val > p->val) {
			return searchPre(p->right, val);
		}
		else return searchPre(p->left, val);

	}
	bool find(string val) {
		return searchRec(root, val);
	}
	bool almostFind(string val) {
		return searchPre(root, val);
	}
	
};

int main() {
	AVLTree tree;

	// Insert values
	tree.inSert("abcd");
	tree.inSert("xyz");
	cout << tree.almostFind("d");
	return 0;
}

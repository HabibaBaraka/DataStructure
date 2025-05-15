// trie.cpp 

#include <iostream>
#include<vector>
#include<map>
using namespace std;
class Trie {
private:
	static const int MAXChar = 26;
	map<string, Trie*>child;
	bool isLeaf{};//the word is complete
public:
	Trie() {
		// set arr to 0s , here set pointers to NULL
		// ignore this 
		//memset(child, 0, sizeof(child));
	}

	void insert(vector<string>&v) {
		Trie* curr = this;//root
		for (auto c : v) {
			if (!(curr->child.count(c)))curr->child[c] = new Trie();
			curr = curr->child[c];
		}
			curr->isLeaf = 1;
	}
	
	bool PathExist(vector<string>& v) {
		Trie* cur = this;//root
		for (auto c : v) {
			if (!cur->child.count(c))return 0;
			cur = cur->child[c];
		}
		return cur->isLeaf;
	}
	bool subPathExist(vector<string>& v) {
		Trie* cur = this;//root
		for (auto c : v) {
			if (!cur->child.count(c))return 0;
			cur = cur->child[c];
		}
		return 1;
	}

	

};
int main()
{
	Trie tree;
	vector<string>path;
	path = { "home", "software", "eclipse" };
	tree.insert(path);
	path = { "home", "software", "eclipse", "bin" };
	tree.insert(path);
	path = { "home", "installed", "gnu" };
	tree.insert(path);
	path = { "user", "mostafa", "tmp" };
	tree.insert(path);

	path = { "user", "mostafa", "tmp" };
	cout << tree.subPathExist(path) << "\n";
	path = { "user", "mostafa" };
	cout << tree.subPathExist(path) << "\n";
	path = { "user", "most" };
	cout << tree.subPathExist(path) << "\n";
	path = { "user", "mostafa", "tmp" };
	cout << tree.PathExist(path) << "\n";


}

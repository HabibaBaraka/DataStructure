// trie.cpp 

#include <iostream>
#include<vector>
#include<map>
using namespace std;
class Trie {
private:
	static const int MAXChar = 26;
	Trie* child[26];
	bool isLeaf{};//the word is complete
public:
	Trie() {
		// set arr to 0s , here set pointers to NULL
		// ignore this 
		memset(child, 0, sizeof(child));
	}

	void insert(string s) {
		Trie* curr=this ;//root
		for (char c : s) {
			int idx = c - 'a';
			if (!curr->child[idx]) curr->child[idx] = new Trie();
			curr = curr->child[idx];
		}
		curr->isLeaf = true;
	}
	void rec(Trie* root, string cur, vector<string>& v) {
		// base case
		if (root->isLeaf)v.push_back(cur);
		// transition
		for (int i = 0; i < 26; i++) {
			if (root->child[i]) {
				char k = (char)(i + 'a');
				rec(root->child[i], cur+k, v);
			}

		}
	}
	void get_all_strings(vector<string>&v) {
		
		rec(this, "", v);
	}
	
	
};
int main()
{
	Trie tree;

	tree.insert( "a");
	tree.insert( "z");
	tree.insert("b");
	tree.insert( "c");

	vector<string> result;
	tree.get_all_strings(result);

	for (const string& word : result)
		cout << word << endl;

}

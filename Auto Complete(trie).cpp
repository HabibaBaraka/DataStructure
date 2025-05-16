// trie.cpp 

#include <iostream>
#include<vector>
#include<map>
using namespace std;
class Trie {
private:
	static const int MAXChar = 26;
	map<string, Trie*>child;
	//bool isLeaf{};//the word is complete
public:
	Trie() {
		// set arr to 0s , here set pointers to NULL
		// ignore this 
		//memset(child, 0, sizeof(child));
	}

	void insert(string s) {
		if (!child.count(s))child[s] = new Trie;
	
	}
	void autocomplete(string s, vector<string>& v)
	{
		for (auto ss : child) {
			bool f = 1;
			for (int i = 0; i < s.size();i++) {
				if (s[i] != ss.first[i]||(ss.first.size() < s.size())) { f = 0; break;; }
			}
			if (f)v.push_back(ss.first);
		}
	}
	
};
int main()
{
	Trie tree;
	

	tree.insert("abcd");
	tree.insert("ab");
	tree.insert("abx");
	tree.insert("abyz");
	tree.insert("xyz");
	tree.insert("a");
	tree.insert("bcd");

	vector<string> res;
	tree.autocomplete("ab", res);
	for (int i = 0; i < (int)res.size(); ++i)
		cout << res[i] << "\n";


}

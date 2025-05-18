// trie.cpp 

#include <iostream>
#include<vector>
#include<map>
using namespace std;
class Trie {
private:
	static const int MAXChar = 26;
	map<char, Trie*>child;
	
	bool isLeaf{};//the word is complete
public:
	Trie() {
		// set arr to 0s , here set pointers to NULL
		// ignore this 
		//memset(child, 0, sizeof(child));
	}

	void insert(string s) {
		Trie* cur = this;
		for (char c : s) {
			
			if (!cur->child.count(c))cur->child[c] = new Trie;
			cur = cur->child[c];
		}
		cur->isLeaf = 1;
	}
	void print() {

	}
	void generate(string s) {
		for (int i = 0; i < s.size(); i++) {
			string sub = "";
			for (int j = i; j < s.size(); j++) {
				sub += s[j];
				insert(sub);
			}
		}
		print();
	}
	bool search(string s) {
		Trie* cur = this;
		for (char c : s) {
			if (!cur->child[c]) {
				return 0;
			}
			cur = cur->child[c];
		}
		return cur->isLeaf;
	}
	void list_substr(string s, vector<string>& v)
	{
		generate(s);
		for (auto it : v) {
			if (search(it)) {
				cout << it << " ";
			}
		}
		cout << "\n*****\n";

	}
};
int main()
{
	Trie tree;
	

	string str = "heyabcdtwxyw";
	vector<string> queries = { "xy", "ab", "t", "yz" };
	tree.list_substr(str, queries);
	return 0;

}

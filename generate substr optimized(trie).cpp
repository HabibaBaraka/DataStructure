// trie.cpp 

#include <iostream>
#include<vector>
#include<map>
#include<set>
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
	void ist_substr(string s, vector<string>& v)
	{
		
		for (auto it : v) {
			insert(it);
		}
		set<string>found;
		for (int i = 0; i < s.size(); i++) {
			Trie* cur = this;
			string sub = "";
			for (int j = i; j < s.size(); j++) {
				if (!cur->child.count(s[j]))break;
				sub += s[j];
				cur = cur->child[s[j]];
				if (cur->isLeaf)found.insert(sub);
				
				
			}
		}
		for (auto it : v) {
			if (found.count(it)) {

				cout << it << "\n";
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
	tree.ist_substr(str, queries);
	return 0;

}//string is long  in this case so it

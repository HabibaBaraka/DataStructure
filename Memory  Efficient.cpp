// trie.cpp 

#include <iostream>
#include<map>
using namespace std;
class Trie {
private:
//	static const int MAXChar = 26;// now this is huge
	map<char, Trie*>child;
	bool isLeaf{};//the word is complete
public:
	Trie() {
		// set arr to 0s , here set pointers to NULL
		// ignore this 
		//memset(child, 0, sizeof(child));
	}

	void insert(string s) {
		Trie* curr = this;//root
		for (char c : s) {
			
			if (!(curr->child.count(c)))curr->child[c] = new Trie();
			curr=curr-> child[c];
		}
		curr->isLeaf = 1;
	}
	
	bool wordExist(string s) {
		Trie* cur = this;//root
		for (char c : s) {
			if (!cur->child.count(c))return 0;
			cur = cur->child[c];
		}
		return cur->isLeaf;
	}

	

};
int main()
{
	Trie trie;
	
	string s = "bcd";
	reverse(s.begin(), s.end());
	trie.insert(s);
	

}

// trie.cpp 

#include <iostream>
using namespace std;
class Trie {
private:
	static const int MAXChar = 26;
	Trie* child[MAXChar];
	bool isLeaf{};//the word is complete
public:
	Trie() {
		// set arr to 0s , here set pointers to NULL
		memset(child, 0, sizeof(child));
	}

	void insert(string s,int idx) {
		// base case 
		if (idx == (int)s.size()) {
			//lable here complete word
			isLeaf = true;
		}
		else {
			// transition 
			int cur = s[idx] - 'a';
			if (child[cur] == 0) {
				// not exist
				child[cur] = new Trie();
			}
			child[cur]->insert(s, idx + 1);
		}
	}
	bool wordExist(string s,int idx) {
		if (idx == (int)s.size()) {
			// does lable word here?
			return isLeaf;
		}
		// transition 
		int cur = s[idx] - 'a';
		if (!child[cur])return false;
		// such path not exist
		return child[cur]->wordExist(s, idx + 1);
	}
	bool prefixExist(string s, int idx) {

		if (idx == (int)s.size()) {
			// all subword covered
			return true;
		}
		// transition 
		int cur = s[idx] - 'a';
		if (!child[cur])return false;
		// such path not exist
		return child[cur]->prefixExist(s, idx + 1);
	}
// iterative
void insert(string s) {
	Trie* curr = this;//root
	for (char c : s) {
		int cur = c - 'a';
		if (!(curr->child[cur]))curr->child[cur] = new Trie();
		curr=curr-> child[cur];
	}
	curr->isLeaf = 1;
}
bool wordExist(string s) {
	Trie* cur = this;//root
	for (char c : s) {
		int idx = c - 'a';
		if (!cur->child[idx])return 0;
		cur = cur->child[idx];
	}
	return cur->isLeaf;
}

string shortExist(string s) {
	string ans = "";
	Trie* cur = this;//root
	for (char c : s) {
		int idx = c - 'a';
		if (!cur->child[idx])return s;// char is missed in this path
		cur = cur->child[idx];
		ans += c;
		if (cur->isLeaf) {
			return ans;
		}
		
	}
	// we reach to the end of path and no isLeaf
	return s;
}

bool prefixExist(string s) {
	Trie* cur = this;//root
	for (char c : s) {
		int idx = c - 'a';
		if (!cur->child[idx])return 0;
		cur = cur->child[idx];
	}
	return true;
}

};
int main()
{
	Trie trie;
	trie.insert("abcd", 0);
	trie.insert("xyz", 0);
	trie.insert("abf", 0);
	trie.insert("xn", 0);
	trie.insert("ab", 0);
	trie.insert("bcd");
	cout << trie.prefixExist("xy", 0);

}

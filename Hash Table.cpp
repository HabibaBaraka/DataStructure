// HashTable.cpp : 

#include <iostream>
#include<vector>
using namespace std;
class HashTable {
	int N;
	vector<vector<int>>v;
public:
	HashTable(int N) 
	{
		this->N = N; v.resize(N);
	}
	void add(int val) 
	{
		int idx = val % N;
		for (auto it : v[idx]) {
			if (it == val)return;
		}
		v[idx].push_back(val);
	}
	bool exist(int val) 
	{
		int idx = val % N;
		for (auto it : v[idx]) {
			if (it == val)return 1;
		}
		return 0;
	}
	void remove(int val)
	{
		int idx = val % N;
		for (int i = 0; i < v[idx].size();i++) {
			if (v[idx][i] == val)
			{
				v[idx].erase(v[idx].begin() + i);
				return;
			}
		}
		
		
	}

};
// solve collision
/*
* Replacement
* openAddressing
* linear probing
* Quadratic probing 
* chaining // every idx can be linkedlist
* 
*/


int main()
{
	HashTable mp(10);
	mp.add(8);
	mp.add(18);
	cout<<mp.exist(8);
	mp.remove(8);
	cout << mp.exist(8);
}


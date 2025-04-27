// notSame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Queue.cpp 
// simple 
// circuler
// priority queue pq
// dequeue  dq
#include<queue>
#include <iostream>
using namespace std;

class sumLastKElement {
	queue<int>q, q2;
	int k;
public:
	sumLastKElement(int val) {
		 k = val;
	}
	int recieve(int val) {
		q.push(val);
		
			int sum = 0;
			while (!q.empty()) {
				if (q.size() <= k) {
					sum += q.front();
				}
				q2.push(q.front());
				q.pop();
			}
			swap(q, q2);
			return sum;
		
	}
	
};
int main()
{
	sumLastKElement m;
	m.recieve(1);
	m.recieve(2);
	m.recieve(3);
	m.recieve(4);
	m.recieve(5);
	m.recieve(6);
	m.recieve(7);
	m.recieve(8);
	m.recieve(9);
	
}
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

class priorityQueue {
	queue<int>q, q2, q3;

public:
	void enQueue(int val, int pr) {
		if (pr == 1) {
			q.push(val);
		}
		else if (pr == 2) {
			q2.push(val);
		}
		else q3.push(val);
	}
	int deQueue() {
		if (!q.empty()) {
			int x = q.front();
			q.pop();
			return x;
		}
		if (!q2.empty()) {
			int x = q2.front();
			q2.pop();
			return x;
		}
		if (!q3.empty()) {
			int x = q3.front();
			q3.pop();
			return x;
		}
	}
	void display() {
		queue<int>pq;
		cout << "priority_queue Task 1 : ";
		while (!q.empty()) {
			cout << q.front() << " ";
			pq.push(q.front());
			q.pop();
		}
		cout << endl;
		swap(q, pq);
		cout << "priority_queue Task 2 : ";
		while (!q2.empty()) {
			cout << q2.front() << " ";
			pq.push(q2.front());
			q2.pop();
		}
		cout << endl;
		swap(q2, pq);
		cout << "priority_queue Task 3 : ";
		while (!q3.empty()) {
			cout << q3.front() << " ";
			pq.push(q3.front());
			q3.pop();
		}
		cout << endl;
		swap(q3, pq);
	}
};
int main()
{
	priorityQueue pq;
	pq.enQueue(19922, 1);
	pq.enQueue(19876, 1);
	pq.enQueue(17643, 2);
	pq.enQueue(1123, 2);
	pq.enQueue(123, 3);
	pq.enQueue(122, 3);
	pq.display();

}

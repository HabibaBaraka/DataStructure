// Queue.cpp 
// simple 
// circuler
// priority queue pq
// dequeue  dq
#include<cassert>
#include <iostream>
using namespace std;

class queue {
private:
	int Size = 10;
	int arr[10];
	int rear = -1;
	int front = -1;
public:
	queue(int sz) {
		Size = sz;
	}
	void enQueue(int val) {
		assert(rear != Size - 1);
		if (rear == -1 && front == -1) {
			front++;
		}
		arr[++rear] = val;

	}
	void deQueue() {
		assert(rear != -1 && front != -1 && rear >= front);
		front++;
	}
	int peek() {
		assert(rear != -1 && front != -1 && rear >= front);
		return arr[front];
	}
	void disply() {
		assert(rear != -1 && front != -1 && rear >= front);
		for (int i = front; i <= rear; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}



};
int main()
{
	queue q(66);
	q.enQueue(8);
	q.enQueue(5);
	q.enQueue(9);
	q.enQueue(6);
	q.disply();
	q.deQueue();
	q.deQueue();
	q.disply();
	cout << q.peek();
}

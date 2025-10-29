// Queue.cpp 
// simple 
// circuler
// priority queue pq
// dequeue  dq
#include<cassert>
#include <iostream>
using namespace std;

class Cqueue {
private:
	int Size = 10;
	int arr[10];
	int rear = -1;
	int front = -1;
public:
	Cqueue(int sz) {
		Size = sz;
	}
	void enQueue(int val) {
		if (full())return;

		if (rear == Size - 1) {
			rear = 0;
			arr[rear] = val;
		}
		else if (rear == -1 && front == -1) {
			front++;
			arr[++rear] = val;
		}
		else arr[++rear] = val;


	}
	void enQueueFront(int val) {
		if (full())return;

		if (front == 0) {
			front = Size - 1;
		}
		else if (rear == -1 && front == -1) {
			front = rear = 0;
		}
		else front--;
			arr[front] = val;


	}
	void deQueue() {
		assert(rear != -1 && front != -1);
		if (front == Size - 1 && rear != front) {
			front = 0;
		}
		else if (front == rear) {
			rear = front = -1;
		}

		else front++;
	}
	void deQueueRear() {
		assert(rear != -1 && front != -1);

		 if (front == rear) {
			rear = front = -1;
		 }
		 else  if (rear ==0) {
			 rear = Size - 1;
		 }
		 
		else rear--;
	}
	int peek() {

		assert(rear != -1 && front != -1);
		return arr[front];
	}
	int getRear() {

		assert(rear != -1 && front != -1);
		return arr[rear];
	}
	void disply() {
		assert(rear != -1 && front != -1);
		/*for (int i = front; (i % Size) != rear; i++) {
			cout << arr[i%Size] << " ";
		}
		cout << arr[rear];
		cout << '\n';*/
		if (front <= rear) {
			for (int i = front; i <= rear; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
			return;
		}
		for (int i = front; i < Size; i++) {
			cout << arr[i] << " ";
		}
		for (int i = 0; i <= rear; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	bool full() {
		return((front == 0 && rear == Size - 1) || rear + 1 == front);
	}


};
int main()
{
	Cqueue q(4);
	q.enQueue(8);
	q.enQueue(5);
	q.enQueueFront(9);
	q.enQueue(6);
	
	q.disply();
	q.deQueueRear();
	//cout <<'\n' << q.full();
	q.disply();
	q.enQueue(0);
	q.disply();
	cout << q.getRear();
	//cout << q.full();
}

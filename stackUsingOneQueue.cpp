using namespace std;
#include<queue>
#include <iostream>
class stack{
	int size = 0;
	queue<int>q;
public:
	int sz() { return q.size(); }
	void push(int val) {
		int sze = sz();
		q.push(val);
		for (int i = 0; i < sze; i++) {
			q.push(q.front());
			q.pop();
		}

	}
	void pop() {
		q.pop();
	}
	int top() {
		return q.front();
	}
	void display() {
		queue<int>q2;
		q2 = q;
		while (!q2.empty()) {
			cout << q2.front() << " ";
			q2.pop();
		}
		cout << endl;
	}

};



int main()
{
	stack s;
	s.push(8);
	s.push(5);
	s.push(4);
	s.push(2);
	s.display();
	s.pop();
	s.display();
	cout << s.top();
}

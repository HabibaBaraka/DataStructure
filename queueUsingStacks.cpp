
#include <iostream>
#include<stack>
using namespace std;
class Queue {
	stack<int>s, s2;
public:
	void push(int val) {
		while (!s.empty()) {
			s2.push(s.top());
			s.pop();
		}
		s.push(val);
		while (!s2.empty()) {
			s.push(s2.top());
			s2.pop();
		}
	}
	void pop() {
		s.pop();
	}
	int top() {
		return s.top();
	}

};
int main()
{
	Queue q;
	q.push(1);
	q.push(4);
	q.push(2);
	q.push(3);
	q.push(5);
	cout << q.top()<<'\n';
	q.pop();
	cout << q.top()<<'\n';
	q.pop();
	cout << q.top() << '\n';
	q.pop();
	cout << q.top() << '\n';
	q.pop();
}

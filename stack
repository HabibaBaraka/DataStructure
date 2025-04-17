// manualStack.cpp : 
#include <iostream>
#include <cassert>
using namespace std;
const int MAX_SIZE = 100;
template<class t>
class Stack
{
private:
	int top;
	t item[MAX_SIZE];
public:
	Stack() {
		top = -1;
	}
	void push(t val) {
		// if top not equal size-1
		assert(top < MAX_SIZE - 1);
		top++;
		item[top] = val;
	}
	bool empty() {
		return top == -1;
	}
	void pop() {
		// if stack is empty
		assert(top >= 0);
		top--;
	}
	void pop(t& element) {
		// if stack is empty
		assert(top >= 0);
		element = item[top];
		top--;
	}
	void getTop(t& Top) {
		// if stack is empty
		assert(top >= 0);

		Top = item[top];
		//		cout<< Top;
	}
	void print() {
		// if stack is empty
		assert(top >= 0);
		cout << '[';
		for (int i = top; i >= 0; i--) {
			cout << item[i] << " ";
		}
		cout << ']';
		cout << endl;
	}

};

int main()
{
	Stack<string> s;
	//s.push("Eslam");

	s.push("Baraka");
	s.push("Habiba");
	s.print();



}
/*
call by reference you make change on var itself
call by value
*/

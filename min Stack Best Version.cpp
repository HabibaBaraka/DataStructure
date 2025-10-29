// manualStack.cpp : 
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;
const int MAX_SIZE = 100;
//template<class t>
class spicielStack
{
private:
	int minEle;
	stack<int>s;
public:
	void push(int x) {
		if (s.empty()) {
			minEle = x;
			s.push(x);
		}
		else if (x < minEle) {
			s.push(2 * x - minEle);
			minEle = x;
		}
		else s.push(x);
	}
	int top() {
		if (s.top() < minEle) {
			return minEle;
		}
		else return s.top();
	}
	void pop() {
		if (s.top() < minEle) {
			minEle = 2 * minEle - s.top();
			s.pop();
		}
		else s.pop();
	}
	int getMin() {
		if (!s.empty())return minEle;
		return -1;
	}
};

int main()
{
	// challenge min stack ......
	
	spicielStack ss;
	ss.push(2);
		ss.push(3);
		ss.push(0);
		ss.push(1);
		cout << ss.getMin();
}

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
	stack<pair<int, int>>s;
public:
	void push(int x) {
		int newMin = s.empty() ? x : min(x, s.top().second);
		s.push({ x,newMin });
	}
	int top() {
		if (!s.empty())return s.top().first;
		return -1;
	}
	void pop() {
		s.pop();
	}
	int getMin() {
		return s.top().second;
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
		cout << ss.top();
}

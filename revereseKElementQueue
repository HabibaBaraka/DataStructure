//Linked List version
void reverseFirstKElement(int k) {
	if (k > size || size == 0) {
		return;
	}
	stack<int>s;
	for (int i = 0; i < k; i++) {
		s.push(peek());
		deQueue();
	}
	while (!s.empty()) {
		enQueue(s.top());
		s.pop();
	}
	for (int i = 0; i < size - k; i++) {
		enQueue(peek());
		deQueue();
	}
}

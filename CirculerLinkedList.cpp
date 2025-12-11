// CirculerLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class CLL
{
private:
	struct Node {
		int data;
		Node* next;
	};
	Node* head = NULL;
public:
	// here we have marked head it's a head node 
	int countCLL() {
		Node* dummy = head;
		int cnt = 0;
		
		do {
			cnt++;
			dummy = dummy->next;
		}
		while (dummy != head);
		return cnt;
		
	}
	// the same when we want to print CLL
	void printCLL() {
		Node* dummy = head;
		int cnt = 0;

		do {
			cout << dummy->data << " ";
			dummy = dummy->next;
		} while (dummy != head);
		cout << endl;
	}
	void insertAtBegin(int val) {
		Node* cur = head, * new_node = new Node;
		new_node->data = val;
		new_node->next = new_node;
		if (head == nullptr) {
			head = new_node;
			return;
		}
		
		while (cur->next != head) {
			cur = cur->next;
		}
		cur->next = new_node;
		new_node->next = head;
		head = new_node;
	}
	void insert(int val){
		Node* cur = head, * new_node = new Node;
		new_node->data = val;
		new_node->next = new_node;
		if (head == nullptr) {
			head = new_node;
			return;
		}

		while (cur->next != head) {
			cur = cur->next;
		}
		cur->next = new_node;
		new_node->next = head;
	}
	void dltLast() {

		Node* cur = head;
		if (cur == nullptr)return;
		if (cur->next == head) {
			head = nullptr;
		}
		while (cur->next->next != head) {
			cur = cur->next;
		}
		cur->next->next = nullptr;
		delete cur->next;
		cur->next = head;

	}
	void dltFront() {
		Node* cur = head;
		if (cur == NULL)return;
		if (cur->next == head) {
			delete head;
			head = NULL;
			return;
		}
		Node*nhead = head->next;
		while (cur->next != head) {
			cur = cur->next;
		}
		cur->next = nhead;
		delete head;
		head = nhead;
	}

};


int main()
{
	CLL LL;
	LL.insertAtBegin(4);
	LL.insertAtBegin(7);
	LL.insertAtBegin(8);

	LL.printCLL();
	LL.dltFront();
	LL.printCLL();
	cout << LL.countCLL();
}

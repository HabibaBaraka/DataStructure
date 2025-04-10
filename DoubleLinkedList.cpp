// DoubleLinkedList.cpp :
// dlt delete
// F first
// B back
#include <iostream>
#include<cassert>
using namespace std;
/*{يقُولونَ هَلْ لَنَا مِنَ الأَمْرِ مِنْ شَيْءٍ قُلْ إِنَّ الْأَمْرَ كُلَّهُ لِلَّهِ}

"وما شاء الله كان، وما لم يشأ لم يكن ..."*/
class DoublyLinkedList {
 private:
	 struct Node {
		 int data;
		 Node* next;
		 Node* pre;
	 };
	 Node* first, * last;
	 int len = 0;
  public:
	  void insertBegin(int val) {
		  Node* nn = new Node{ val };
		  if (len == 0) {
			  nn->pre = nullptr;
			  first = last = nn;
			  len++; return;
		  }
		 //else 
			  nn->pre = nullptr;
			  nn->next = first;
			  first->pre = nn;
			  first = nn;
			  len++;
		  
	  }
	  void insert(int val) {
		  Node* nn = new Node{ val };
		  if (len == 0) {
			  nn->pre = nn->next=nullptr;
			  first = last = nn;
			  len++; return;
		  }
		  last->next = nn;
		  nn->pre = last;
		  nn->next = nullptr;
		  last = nn;
		  len++;
	  }
	  void insertAt(int pos,int val) {
		  assert(pos >= 1 && pos <= len + 1);
		  if (pos == 1) {
			  insertBegin(val); return;
		  }
		  if (pos == len + 1) {
			  insert(val);
			  return;
		  }
		  else {
			  Node* nn = new Node{val};
			  Node* before = first;
			  for (int i = 1; i < pos-1; i++) {
				  before = before->next;
			  }
			  nn->pre = before;
			  nn->next = before->next;
			  (nn->next)->pre = nn;
			  before->next = nn;

		  }
	  }
	  void print() {
		  Node* cur;
		  cur = first;
		  while (cur) {
			  cout << (cur->data) << " ";
			  cur = cur->next;
		  }
		  cout << endl;
	  }
	  void dltF() {
		  assert(len > 0);
		  if (len == 1) {
			  free(first);
			  first = last = nullptr;
			  len = 0;
			  return;
		  }
		  Node* nn;
		  nn = first->next;
		  nn->pre = nullptr;
		  free(first);
		  first = nn;
		  len--;
	  }
	  void dltB() {
		  if (len == 1) {
			  free(first);
			  first = last = nullptr;
			  len = 0;
			  return;
		  }
		  Node* nn = last->pre;
		  nn->next = nullptr;
		  free(last);
		  last = nn;
		  len--;
	  }
	  void dltAt(int pos) {
		  assert(pos <= len && pos >= 1);
		  if (pos == 1) {
			  dltF(); return;
		  }
		  if (pos == len) {
			  dltB();
			  return;
		  }
		  Node* before = first;
		  for (int i = 1; i < pos - 1; i++) {
			  before = before->next;
		  }
		  Node* cur = before->next;
		  before->next = cur->next;
		  (cur->next)->pre = before;
		  free(cur);
		  len--;
	  }
	  void dltData(int val) {
		  if (first->data == val) {
			  dltF();
			  return;
		  }
		  if (last->data == val) {
			  dltB();
			  return;
		  }
		  Node* cur = first;
		  while (cur && cur->data != val) {
			  cur = cur->next;
		  }
		  if (cur == nullptr)cout<< -1;
		  else {
			  Node* before = cur->pre;
			  before->next = cur->next;
			  (cur->next)->pre = before;
			  free(cur);
			  len--;
		  }
	  }
	  void reverseWithLast() {
		  Node* nn = last;
		  while (last) {
			  cout << last->data << " ";
			  last = last->pre;
		  }
		  cout << endl;
	  }
	  ~DoublyLinkedList() {
		  while (first) {
			  dltF();
		  }
	  }
};
int main()
{
	DoublyLinkedList dl;

	dl.insert(6);
	dl.insert(5);
	dl.insert(4);
	dl.insertAt(4,1);
	dl.print();
	
	dl.reverseWithLast();
}
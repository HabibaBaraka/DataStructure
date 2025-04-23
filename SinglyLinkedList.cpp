// SinglyLinkedList.cpp 

/*{يقُولونَ هَلْ لَنَا مِنَ الأَمْرِ مِنْ شَيْءٍ قُلْ إِنَّ الْأَمْرَ كُلَّهُ لِلَّهِ}
 
"وما شاء الله كان، وما لم يشأ لم يكن ..."*/
#include <iostream>
#include<cassert>
using namespace std;
struct Node
{
	int data;
	Node* next;//معناها إن المؤشر ده بيشاور على كائن من نوع Node
};

class  LinkedList
{
private:
	 Node *head = NULL;
	 Node* tail = NULL;
	 int length = 0;
public:
	Node* getHead() {
		return head;
	}
	Node* getTail() {
		return tail;
	}
	void insert_node(int val) {
		length++;
		Node* new_node,*cur;
		new_node = new Node;
		new_node->data = val;
		
		if (head == NULL) {
			head =tail= new_node;
			new_node->next = NULL;
			return;
		}
		/*
		tail->next = new_node;
		tail = new_node;
		new_node->next = NULL;*/
		cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = new_node;
		new_node->next = NULL;
	}
	Node* first() {
		return head;
	}
	int get_length() {
		return length;
	}
	void displayLinkedList() {

		assert(head != NULL);
		Node* cur;
		cur = head;
		while (cur != NULL) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << '\n';

	}
	void print_reverse(Node* ptr) {
		// i can't understand this until now
		if (ptr == NULL)return;
		print_reverse(ptr->next);
		cout << ptr->data << " ";
	}
	void delete_node(int val) {
		Node* cur, * previous;
		cur = head;
		bool f = 0;
		if (cur->data == val) {
			head = cur->next;
			free(cur);
			f = 1;
		}
		while (cur != NULL && !f) {
			previous = cur;
			cur = cur->next;
			if (cur->data == val) {
				previous->next = cur->next;
				free(cur);
				f = 1;
			}
		}
	}
	void delete_node_version2(int val) {
		Node* cur, * pre;
		cur = head;
		pre = head;
		bool f = 0;
		if (cur->data == val) {
			head = cur->next;
			free(cur);
			return;
		}
		while (cur->data != val) {
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		free(cur);
	}
	void inserAtbegin(int val) {
		Node* new_node;
		new_node = new Node;
		new_node->data = val;
		new_node->next = head;
		head = new_node;

	}
	void deleteAtbegin() {
		Node* first;
		assert(head != NULL);
		first = head;
		head = first->next;
		free(first);
	}
	void deleteAtend() {
		assert(head != NULL);
		Node* last, * pre;
		last = head;
		pre = head;
		if (last->next == NULL) {
			head = NULL;
			return;
		}
		while (last->next != NULL) {
			pre = last;
			last = last->next;
		}
		pre->next = NULL;
		free(last);
	}
	void deleteAtendVersion2() {
		assert(head != NULL);
		Node* last;
		last = head;

		if (last->next == NULL) {
			head = NULL;
			return;
		}
		while (last->next->next != NULL) {
			last = last->next;
		}
		free(last->next);
		last->next = NULL;
	}
	Node* node_th(int n) {
		int cnt = 1;
		assert(head != NULL);
		for (Node* cur = head; cur; cur = cur->next) {
			if (cnt == n)return cur;
			cnt++;
		}
		return nullptr;
	}
	int search(int val) {
		assert(head != NULL);
		int cnt = 1;
		for (Node* cur = head; cur; cur = cur->next) {
			if (val == cur->data)return cnt;
			cnt++;
		}
		return -1;
	}
	int improved_Search(int val) {
		int cnt = 1;
		for (Node* cur = head, *pre = nullptr; cur; pre = cur, cur = cur->next) {
			if (cur->data == val) {

				if (pre != nullptr) {
					swap(pre->data, cur->data);
				}
				return cnt;
			}
			cnt++;
		}
		return -1;
	}
	bool is_same(LinkedList List2) {
		if (length!= List2.get_length())return 0;
		Node* cur = head;
		Node* ptr = List2.first();
		while (cur != NULL&&ptr!=NULL) {
			if (cur->data != ptr->data)return 0;
			cur = cur->next;
			ptr = ptr->next;
		}
		//if (cur != ptr)return 0;
		return 1;
	}
	int node_thBack(int idx) {
		Node* cur = head;
		int cnt = length;
		while (cur != NULL) {
			if (cnt == idx)return cur->data;
			cur = cur->next;
			cnt--;
		}
		return -1;
	}
	void delete_n_th(int idx) {
		assert(idx > 0 && idx <= length);
		if (idx == 1) {
			deleteAtbegin();
			return;
		}
		Node* previous = node_th(idx - 1), *cur = previous->next;
		previous->next = cur->next;
		cur->next = nullptr;
		free(cur);
	}
	void swapPairs() {
		assert(length > 1);
		Node* cur = head,*pre=cur->next;
		int cnt = 1;
		while (cnt++ <= length) {
			if (cnt & 1) {
				swap(pre->data, cur->data);
			}
			pre = cur;
			cur = cur->next;
			
		}
	}
	void dltEvenPos() {
		assert(length > 1);
		for (int i = length; i >= 1; i--) {
			if (i % 2 == 0)delete_n_th(i);
		}
	}
	void reverse() {
		Node* pre, * cur;
		pre = nullptr, cur = head;
		while (cur != NULL) {
			Node* next = cur->next;
			cur->next = pre;// reverse direction
			pre = cur;// move
			cur = next;// move
		}
		head = pre;
	}
	void insertSorted(int val) {
		length++;
		Node* new_node;
		new_node = new Node;
		new_node->data = val;
		new_node->next = nullptr;
		if (head == NULL) {
			head = new_node;
			tail = new_node;
			return;
		}
		if (val <= head->data) {
			inserAtbegin(val);
			return;
		}
		Node* cur, * pre;
		cur = head;
		pre = head;
		if (val > tail->data) {
			tail->next = new_node;
			tail = new_node;
			return;
		}
		while (cur != NULL) {
			if (cur->data >= val) {
				pre->next = new_node;
				new_node->next = cur;
				break;
			}
			else {
				pre = cur;
				cur = cur->next;
			}
		}
	}
	void swapTail_Head() {
		Node* n_head=new Node, * n_tail=new Node;

		n_head->data = tail->data;
		n_head->next = head->next;
		n_tail->data = head->data;
		n_tail->next = nullptr;
		head = n_head;
		tail = n_tail;
	}
	void dltLastOccur(int val){
		for (int i = length; i >= 1; i--) {
			Node* cur;
			cur = new Node;
			cur = node_th(i);
			if (cur->data == val) {
				delete_n_th(i);
				return;
			}
		}
		length--;
	}
	void removeduplicate() {
		Node* cur = head,*next;
		while (cur != nullptr) {
			next = cur->next;
			while (next!=nullptr&&cur->data == next->data) {
				//delete this
				cur->next = next->next;
				
				next = cur->next;

			}
			cur = cur->next;
		}
	}
	void rotateK(long k) {
		k %= length;
		Node* cur = head,*pre=head;
		for (int i = 1; i < k; i++) {
			cur = cur->next;
		}
		pre = cur;//new tail
		cur = cur->next;//new head
		pre->next = nullptr;
		tail->next = head;
		head = cur;
		tail = pre;
	}
	void moveBack(int k) {
		if (!head||!head->next)return;
		Node* cur, * pre,*oldTail;
		cur = head;
		pre = nullptr;
		oldTail = tail;

		while (cur!=oldTail) {
			if (cur->data == k) {
				Node* dlt = cur;
				if (cur==head) {
					head = cur->next;
					cur = head;
				}
				else {
					pre->next = cur->next;
					cur = pre->next;
				}
				dlt->next = nullptr;
				tail->next = dlt;
				tail = dlt;
				
			}
		
			else {
				pre = cur;
				cur = cur->next;
			}
		}
	}
	int max() {
		Node* cur = head;
		int mx = 0;
		while (cur != nullptr) {
			if (mx <cur->data)mx = cur->data;
			cur = cur->next;
		}
		return mx;
	}
	int max2(Node* node) {
		// i can't understand this until now
		if (!node)return INT_MIN;
		int nextmx = max2(node->next);
		return std::max(nextmx, node->data);
	}
	void arrangeEven_and_Odd() {
		int cnt = 1;
		Node* cur, * pre;
		cur = head;
		pre = nullptr;
		
		while (cur&&cnt<=length) {
			if (cnt % 2 == 0) {
				pre->next = cur->next;
				Node* move;
				move = cur;
				cur->next = nullptr;
				tail->next = move;
				move->next = nullptr;
				tail = move;
				cur = pre->next;
				
			}
			else {
				pre = cur;
				cur = cur->next;
			}
			cnt++;

		}
	}
	void removeRepititive() {
		Node* pre, * cur, * next;
		pre = nullptr;
		cur = head;
		while (cur!=NULL) {
			next = cur->next;
			if (next&&cur->data == next->data) {
				while (next && cur->data == next->data) {
					cur->next = next->next;
					next = cur->next;
				}
				if (pre == nullptr) { head = cur->next; }//in this case pre still nullptr 
				else pre->next = cur->next;
				if (pre)cur = pre->next;
				else cur = head;
			}
			else {
				pre = cur;
				cur = cur->next;
			}
		}
	}
	void alternate(LinkedList& List) {
		Node* cur, * cur2;
		cur = head;
		cur2 = List.getHead();
		while (cur!=nullptr &&cur2!=nullptr) {
			Node* temp = cur->next;
			Node* temp2 = cur2 -> next;
			cur->next = cur2;
			cur2->next = temp;
			cur = temp;
			cur2 = temp2;
		}
		
		while (cur2 != nullptr) {
			insert_node(cur2->data);
			cur2 = cur2->next;
		}
	}
	void addHugeNum(Node* head, Node* head2) {
		Node* cur = head, * cur2 = head2, * pre = nullptr;
		int carry = 0;
		while (cur || cur2 || carry > 0) {
			int sum = carry;
			if (cur) {
				sum += cur->data;
			}
			if (cur2) {
				sum += cur2->data;
			}
			
			int sum2 = sum%10;
			carry = sum / 10;
			if (cur) {
				cur->data = sum2;
				pre = cur;
				cur = cur->next;
				
			}
			else {
				Node* node=new Node;
				node->data = sum2;
				node->next = nullptr;
				pre->next = node;
				pre = node;
			}
			if (cur2) {
				cur2 = cur2->next;
			}
		}
	}
void deleteNode(Node* node) {
       
        Node*nn;
        nn=node->next;
        node->data=nn->data;
        node->next=nn->next;
        delete nn;
        
    }
	Node* deleteLastOccurrence(Node* head, int key) {
    Node *last = nullptr, *lastPrev = nullptr;
    Node *curr = head, *prev = nullptr;

    // Traverse the list to find the last 
  	// occurrence of the key
    while (curr != nullptr) {
        if (curr->data == key) {
            lastPrev = prev;
            last = curr;
        }
        prev = curr;
        curr = curr->next;
    }

    // If the key was found
    if (last != nullptr) {
        
      	// If last occurrence is not the head
        if (lastPrev != nullptr) {
            lastPrev->next = last->next;
        } else {
          
            // If last occurrence is the head, 
          	// move head to next node
            head = head->next;
        }
        delete last;
    }

    return head;
}

};

int main()
{
	
	LinkedList List,List2;
	
	List.insert_node(2);
	
	List.insert_node(4);
	List.insert_node(3);
	List2.insert_node(5);
	List2.insert_node(6);

	
	
	return 0;
}

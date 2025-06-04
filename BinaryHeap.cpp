// BinaryHeap.cpp :

#include <iostream>
#include<vector>
using namespace std;
class Heap {
	// O(log(n))
	//space O(log(n)
	vector<int>arr;
	void MAX_Heapify(int i) {
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int mx = i;

		//base case
		if (l < arr.size() && arr[l] > arr[mx]) {
			mx = l;
		}
		if (r < arr.size() && arr[r] > arr[mx]) {
			mx = r;
		}
		//transition
		if (mx != i) {
			swap(arr[i], arr[mx]);
			MAX_Heapify(mx);
		}


	}
	void build() {
		//O(n)
		int n = arr.size();
                // the correct Q here why this loop go from n over 2 down to 1 ??!
		// the answer is simple due to from n over 2 plus 1 to n these are leaves .
		for (int i = (n / 2) - 1; i >= 0; i--) {
			MAX_Heapify(i);
		}
	}
public:
	
	void insert(int x) {
	arr.push_back(x);
	
	int j = arr.size() - 1;
	int i = j;
	while (arr[i / 2] < arr[j])
	{
		swap(arr[i / 2], arr[j]);
		j /= 2;
		i = j;
	}
}
	int dlt() {
	int x = arr[0];
	swap(arr[0], arr[arr.size() - 1]);
	arr.pop_back();
	int i = 0;
	while(true)
	{
	  int l = 2 * i+1;
	  int r = 2 * i + 2;
	  int idx = i;
	  if (l < arr.size() && arr[idx] < arr[l])idx = l;
		
	  if (r < arr.size() && arr[idx] < arr[r])idx = r;
	 
	  if (idx == i)break;
	  swap(arr[i], arr[idx]);
	  i = idx;
	}
	
	return x;
}
	void print() {
		//O(n)
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	Heap h;
	h.insert(10);
	h.insert(20);
	h.insert(5);
	h.insert(30);
	h.insert(15);

	h.print();   // قبل الحذف
	h.dlt();   // حذف الجذر (أكبر عنصر)
	h.print();   // بعد الحذف
}

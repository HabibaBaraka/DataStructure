// BinaryHeap.cpp :

#include <iostream>
using namespace std;
class Heap {
	// O(log(n))
	//space O(log(n)
	void heapify(int arr[], int n, int i) {
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int mx = i;

		//base case
		if (l<n&&arr[l] > arr[mx]) {
			mx = l;
		}
		if (r<n&&arr[r] > arr[mx]) {
			mx = r;
		}
		//transition
		if (mx != i) {
			swap(arr[i], arr[mx]);
			heapify(arr, n, mx);
		}
		
		
	}
public:
	
	void build(int arr[],int n) {
		//O(n)
		for (int i = (n / 2) - 1; i >= 0; i--) {
			heapify(arr, n, i);
		}
	}
	void sortHeap(int arr[], int n) {
		// O(nlog(n))
		build(arr, n);
		for (int i = n - 1; i >= 0; i--) {
			swap(arr[0], arr[i]);
			heapify(arr,i,0);
		}
	}
	void print(int arr[],int n) {
		//O(n)
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	Heap pq;
	int arr[] = { 4,7 ,8,23,90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "before Heap\n";
	pq.print(arr, n);
	cout << "after Heap\n";
	pq.build(arr, n);
	pq.print(arr, n);
	cout << "after sort Heap\n";
	pq.sortHeap(arr, n);
	pq.print(arr, n);

}
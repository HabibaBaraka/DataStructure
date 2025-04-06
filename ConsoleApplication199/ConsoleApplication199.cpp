/*
								  "صلي على النبي"
			  * قَالُوا سُبْحَانَكَ لَا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا ۖ إِنَّكَ أَنتَ الْعَلِيمُ الْحَكِيمُ *
*/
#include<vector>
#include <iostream>
using namespace std;
#include<map>
#include<algorithm>
#include<cassert>
#define ll long long
#define ld long double
#define Y "YES"
#define O "NO"
#define el cout<<endl;
class Vector
{ private:
	int* arr{ nullptr };
	int size{ 0 };
	int capacity{ };
	void expand_Capacity() {
		capacity *= 2;// in usual  it doubled
		int* arr2 = new int[capacity];
		for (int i = 0; i < size; i++) {
			arr2[i] = arr[i];
		}
		swap(arr, arr2);
		delete[] arr2;
	}
 public:
	 Vector(int n) {
		 if (n < 0) {
			 n = 1;
		 }
		 size = n;
		 arr = new int[size + capacity] {};
	 }
	 ~Vector() {
		 delete[]arr;
		 arr = nullptr;
	 }
	 void push_back(int val) {
		 if (size == capacity)expand_Capacity(); //check capacity
		 int* arr2 = new int[size + 1]; // new arr with bigger size 

		 for (int i = 0; i < size; i++) {// copy  old data
			 arr2[i] = arr[i];
		 }
		 size++;
		 arr2[size-1] = val;// insert new data
		 swap(arr2, arr); // swap pointers
		 delete[]arr2; // delete temp arr
	 }
	 void push_front(int val) {// the same  what happened in push back with only small different
		 if (size == capacity)expand_Capacity();
		 int* arr2 = new int[size + 1];
		 for (int i = 0; i < size; i++) { 
			 arr2[i] = arr[i];
		 }
		 for (int i = 0; i < size; i++) {
			 swap(val, arr2[i]);
		 }
		 size++;
		 arr2[size-1] = val;
		
		 swap(arr2, arr);
		 delete[]arr2;
	 }
	 int back() {
		 return arr[size - 1];
	 }
	 int front() {
		 return arr[0];
	 }
	 int Size(){
		 return size;
	 }
	 int find(int val) {
		 for (int i = 0; i < size; i++) {
			 if (arr[i] == val)return i;
		 }
		 return -1;
	 }
	 void clear() {
		 size = 0;
	 }
	 void print() {
		 for (int i = 0; i < size; i++) {
			 cout << arr[i] << " ";
		 }
		 
	 }
	 int get(int idx) {
		 assert(idx >= 0 && idx < size);// avoid crush this when no sto the program
		 return arr[idx];
	 }
	void set(int idx, int val) {
		assert(idx >= 0 && idx < size);
		for (int i = 0; i < size; i++) {
			if (i == idx)arr[i] = val;
		}
	}
	void leftRotation() {
		int temp = arr[0];
		for (int i = 0; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[size - 1] = temp;
	}
	void rightRotation() {
		int temp = arr[size - 1];
		for (int i = size - 2; i >= 0; i--) {
			arr[i + 1] = arr[i];
		}
		arr[0] = temp;
	}
	void rightRotation(int times){
		times %= size;
		while (times--) {
			rightRotation();
		}
	}
	void pop(int idx){
		cout<< get(idx);
		
		int val = -1;
		int* arr2 = new int[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i == idx) {
				
				continue;
			}
			arr2[j] = arr[i];
			j++;
		}
		swap(arr2, arr);
		delete[]arr2;
		size--;
	}
	int delete_pos(int idx) {
		int value = arr[idx];
		for (int i = idx + 1; i < size; ++i) {
			arr[i - 1] = arr[i];
		}
		size--;
		return value;
	}
	int find_transposision(int val) { // to speed excute find function
		if (arr[0] == val)return 0;
		
		for (int i = 1; i < size; i++) {
			if (arr[i] == val) {
				swap(arr[i], arr[i - 1]);
				return i - 1;
				
			}
		}
		return -1;
	}
};

int main()
{
	int tc = 1; //n >> tc;
	while (tc--) {
		int n;
		cin >> n;
		Vector v(n);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.set(i, x);
		}
		for (int i = 0; i < n; i++) {
			cout << v.find_transposision(30); el;
			v.print(); el;
		}
	}
}

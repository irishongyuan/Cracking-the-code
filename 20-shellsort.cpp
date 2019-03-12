#include <iostream>
using namespace std;

void shellsort(int a[], int n) {
	int gap = n / 2;
	
	while(1 <= gap) {
		for(int i = gap; i < n; i ++) {
			int j;
			int temp = a[i];
			//²åÈëÅÅÐò·¨ 
			for(j = i - gap; j >= 0 && temp < a[j]; j -= gap) {
				a[j + gap] = a[j]; 
			}
			a[j + gap] = temp;
		}
		gap /= 2;
	}
} 

void printarray(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << a[i] << " "; 
	}
	cout << endl;
}

int main() {
	int a[] = {10,12,3,8};
	int n = sizeof(a) / sizeof(int);
	printarray(a, n);
	shellsort(a, n);
	printarray(a, n);
}

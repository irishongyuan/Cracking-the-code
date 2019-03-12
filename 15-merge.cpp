#include<iostream>
using namespace std;

void merge(int a[], int b[], int m, int n) {
	int k = m + n - 1;
	int i = m - 1;
	int j = n - 1;
	while(i >= 0 && j >= 0) {
		int n = k;
		a[k--] = (a[i] > b[j]) ? a[i--] : b[j--];
	}
	while(j >= 0) {
		a[k--] = b[j--];
	}
} 

void printarray(int a[], int m) {
	for(int i = 0; i < m; i++) {
		cout << a[i] << " ";
	} 
}

int main() {
	int a[] = {1, 3, 5, 7, 9};
	int b[] = {2, 4, 6, 8};
	int m = sizeof(a) / sizeof(int);
	int n = sizeof(b) / sizeof(int);
	merge(a, b, m, n);
	cout << "a merge b is:";
	printarray(a, m+1);
}

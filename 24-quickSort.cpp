#include <iostream>
using namespace std;

int partition(int a[], int l, int r) {
    int temp = a[r];
    while (l < r) {
        while (l < r && a[l] <= temp) {
            ++l;
        }
        a[r] = a[l];
        while (l < r && a[r] >= temp) {
            --r;
        }
        a[l] = a[r];
    }
    a[l] = temp;
    return l;
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int ridx = partition(a, l, r);
        cout << a[ridx] << ": ";
        printArray(a, 8);
        quickSort(a, l, ridx-1);
        quickSort(a, ridx+1, r);
    }
}

//int main() {
//    int a[] = {8,3,2,3,4,6,7,9};
//    int size = sizeof(a) / sizeof(int);
//    quickSort(a, 0, size-1);
//}

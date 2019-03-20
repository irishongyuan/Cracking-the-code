#include <iostream>
using namespace std;

int bin_Search(int a[], int n, int val) {
    int start = 0;
    int end = n-1;
    
    while (start <= end) {
        int mid = start + ((end - start) >> 1);
        if(val < a[mid]) {
            end = mid - 1;
        }
        else if(val > a[mid]) {
            start = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

//int main(){
//    int a[] = {1,2,4,6,8,9,11};
//    int size = sizeof(a) / sizeof(int);
//    int findval = 3;
//    int idx = bin_Search(a, size, findval);
//    if(-1 != idx) {
//        cout << "find " << a[idx] << ", the idex is" << idx << endl;
//    }
//    else {
//        cout << "not find " << findval << endl;
//    }
//}

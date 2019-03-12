#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;

void printsubset(vvi set) {
	for(int i = 0; i < set.size(); i++) {
		vi sub = set[i];
		cout << "{" ;
		for(int j = 0; j < sub.size(); j++) {
			cout << sub[j] << " ";
		}
		cout << "}" << endl;
	}
}

vvi subset1(int a[], int size) {
	int n = 1<<size;
	vvi set;
	for(int i = 0; i < n; i++) {
		int j = i;
		int idx = 0;	
		vi sub;
		while(j > 0) {
			if(j & 1) {
				sub.push_back(a[idx]);
			}
			j >>= 1;
			idx++;
		}
		set.push_back(sub);
	}
	return set;
}

//idx代表集合中从第idx位开始的子集 
vvi subset2(int a[], int idx, int size) {
	vvi set;
	
	//empty
	if (idx == size) {
		vi sub;
		set.push_back(sub);
		return set;
	}
	
	vvi rset = subset2(a, idx+1, size);
	for(int i = 0; i < rset.size(); i++) {
		vi sub = rset[i];	
		set.push_back(sub);
		sub.push_back(a[idx]);
		set.push_back(sub);
	}	
	return set;
}

int main() {
	int a[] = {1, 2, 3};
	int n = sizeof(a) / sizeof(int);
	vvi sub1 = subset1(a, n);
	vvi sub2 = subset2(a, 0, n);
	cout << "unrecursion method subset of {1, 2, 3} is: " << endl;
	printsubset(sub1);
	cout << "recursion method subset of {1, 2, 3} is: " << endl;
	printsubset(sub2);
}

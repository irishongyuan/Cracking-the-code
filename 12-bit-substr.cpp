#include<iostream>
#include<vector>
#import<cmath>
using namespace std;

void print_binary(int n) {
	vector<int> bitvec;
	int mask = 1;
	const int bit_len = 8;
	int len = bit_len * sizeof(int);
	while(len--) {
		if(n & mask) {
			bitvec.push_back(1);
		}
		else {
			bitvec.push_back(0);
		}
		mask <<= 1;
	}
	while(!bitvec.empty()) {
		cout << bitvec.back();
		bitvec.pop_back();
	}
	cout << endl;
}

void bit_substr1(int &m, int n, int i, int j) {
	//构造一个第i位到第j位为0，其他位为1的数temp
	int a = (1 << i) - 1; 
	int b = ~((1 << (j+1)) - 1);
	int temp = a | b;
	
	//将temp与m按位与，使得m的第i位到第j位为0，其他位不变 
	m = m & temp;
		
	//将m和左移i位后的n做或操作
	m = m | (n << i); 
}

void bit_substr2(int &m, int n, int i, int j) {
	//保留m中的[0,i)位到（其他位为0）temp
	int temp = m & ((1<<i) - 1);
	
	//使得m的[0,j]位为0，其他位不变 
	m = m >> (j+1);
	m = m << (j+1);
	
	//将m和左移i位后的n和temp做或操作 
	m = m | temp | (n << i);
}

int main() {
	int a = 1 << 10;
	cout << "    m is: ";
	print_binary(a); 
	int b = 21;
	cout << "    n is: ";
	print_binary(b);
	//bit_substr1(a, b, 2, 6); 
	bit_substr2(a, b, 2, 6);
	cout << "new m is: ";
	print_binary(a);
	  
	b = 15;
	cout << "new n is: ";
	print_binary(b);
	//bit_substr1(a, b, 4, 7);
	bit_substr2(a, b, 4, 7);
	cout << "now m is: ";
	print_binary(a); 
	
	//整型 
	int t =  -2;
	cout << "       -2 is：";
	print_binary(t);
	cout << "-2右移一位是：";
	print_binary(t >> 1);
	cout << "-2右移一位是：" << (t >> 1) << endl;
	//无符号整型
	unsigned int ut = pow(2,32) - 2;
	cout << "       " << ut << " is：";
	print_binary(ut);
	cout << ut << "右移一位是：";
	print_binary(ut >> 1);
	cout << ut << "右移一位是：" << (ut >> 1) << endl;
}


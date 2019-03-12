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
	//����һ����iλ����jλΪ0������λΪ1����temp
	int a = (1 << i) - 1; 
	int b = ~((1 << (j+1)) - 1);
	int temp = a | b;
	
	//��temp��m��λ�룬ʹ��m�ĵ�iλ����jλΪ0������λ���� 
	m = m & temp;
		
	//��m������iλ���n�������
	m = m | (n << i); 
}

void bit_substr2(int &m, int n, int i, int j) {
	//����m�е�[0,i)λ��������λΪ0��temp
	int temp = m & ((1<<i) - 1);
	
	//ʹ��m��[0,j]λΪ0������λ���� 
	m = m >> (j+1);
	m = m << (j+1);
	
	//��m������iλ���n��temp������� 
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
	
	//���� 
	int t =  -2;
	cout << "       -2 is��";
	print_binary(t);
	cout << "-2����һλ�ǣ�";
	print_binary(t >> 1);
	cout << "-2����һλ�ǣ�" << (t >> 1) << endl;
	//�޷�������
	unsigned int ut = pow(2,32) - 2;
	cout << "       " << ut << " is��";
	print_binary(ut);
	cout << ut << "����һλ�ǣ�";
	print_binary(ut >> 1);
	cout << ut << "����һλ�ǣ�" << (ut >> 1) << endl;
}


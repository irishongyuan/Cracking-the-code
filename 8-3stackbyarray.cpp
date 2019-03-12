#include <iostream>

using namespace std;

class stackarray1 {
	public:	
		stackarray1(int size) {
			array = new int[size*3];
			this->msize = size;
			ptop[0] = ptop[1] = ptop[2] = -1;
		}
		
		~stackarray1() {
			delete[] array;
		}
		
		void push(int stackNum, int val) {
			if(ptop[stackNum] < (this->msize - 1)) {
				array[stackNum * this->msize + ptop[stackNum] + 1] = val;
				ptop[stackNum]++;
				cout << val << "��" << stackNum << "��ջ�ɹ���" << endl;
			}
			else {
				cout << stackNum << "��ջ���������޷���ջ��" << endl; 
			}
		}
		
		void pop(int stackNum) {
			if(!empty(stackNum)) {
				int val = array[stackNum * this->msize + ptop[stackNum]];
				ptop[stackNum]--;
				cout << stackNum << "��ջ��ջΪ" << val << "�ɹ���" << endl;
			}
			else {
				cout << stackNum << "��ջ�ѿգ����޷���ջ��" << endl; 
			}
		}
		
		int top(int stackNum) {
			if(!empty(stackNum)) {
				int val = array[stackNum * this->msize + ptop[stackNum]];
				return val;
			}
			else {
				cout << stackNum << "��ջ�ѿգ�" << endl; 
			}
		}
		
		bool empty(int stackNum) {
			return ptop[stackNum] ==-1;
		}
		
		int size(int stackNum) {
			return ptop[stackNum]+1;
		}
		
	private:
		int msize;
		int* array;
		int ptop[3];
};

typedef struct node{
	int val, plast;
} node;

class stackarray2 {
	public:
		stackarray2(int size) {
			array = new node[size];
			this->msize = size;
			ptop[0] = ptop[1] = ptop[2] = -1;
			cur = 0;
		}
		
		void push(int stackNum, int val) {
			if (cur < this->msize) {
				array[cur].val = val;
				array[cur].plast = ptop[stackNum];
				ptop[stackNum] = cur;
				cur++; 
				cout << val << "��" << stackNum << "��ջ�ɹ���" << endl;
			}
			else {
				cout << stackNum << "��ջ���������޷���ջ��" << endl; 
			}
		}
		
		void pop(int stackNum) {
			if(!empty(stackNum)) {
				int val = array[ptop[stackNum]].val;
				ptop[stackNum] = array[ptop[stackNum]].plast;
				cout << stackNum << "��ջ��ջΪ" << val << "�ɹ���" << endl;
			}
			else {
				cout << stackNum << "��ջ�ѿգ����޷���ջ��" << endl; 
			}
		}
		
		int top(int stackNum) {
			if(!empty(stackNum)) {
				int val = array[ptop[stackNum]].val;
				return val;
			}
			else {
				cout << stackNum << "��ջ�ѿգ�" << endl; 
			}
		}
		
		bool empty(int stackNum) {
			return ptop[stackNum] ==-1;
		}
		
		int size(int stackNum) {
			return ptop[stackNum]+1;
		}
		
	private:
		int msize;
		node * array;
		int ptop[3];
		int cur;
};

int main() {
	stackarray1 stack(1);
	stack.push(1,1);
	stack.top(0);
	cout << "1��ջͷΪ" << stack.top(1) << endl;
	cout << stack.empty(1) << endl;
	stack.push(1,2);
	cout << "1��ջ��" << stack.size(1) << "��Ԫ��" << endl; 
	stack.pop(1);
	cout << stack.empty(2) << endl;
	stack.top(1);
	cout << "----------------" << endl;
	stackarray2 stack2(4);
	stack2.push(0,1);
	stack2.push(1,2);
	stack2.push(2,3);
	stack2.push(1,4);
	cout << "0��ջͷΪ" << stack2.top(0) << endl;
	cout << "1��ջͷΪ" << stack2.top(1) << endl;
	cout << stack2.empty(0) << endl;
	stack2.push(0,2);
	cout << "0��ջ��" << stack2.size(0) << "��Ԫ��" << endl; 
	stack2.pop(0);
	cout << stack2.empty(0) << endl;
	stack2.top(0);
}

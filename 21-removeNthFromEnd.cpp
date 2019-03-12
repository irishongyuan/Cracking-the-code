#include<iostream>
using namespace std;
 
struct ListNode {
	int val;
	ListNode* next;
};

ListNode* init(int a[], int n) {
	ListNode *head, *last;
	for(int i= 0; i < n; i++) {
		ListNode* node = new ListNode;
		node->val = a[i];
		if(i == 0) {
			head = node;
			last = node;
		}
		else {
			last->next = node;
			last = node;
		}
		if(i == n-1) {
			node->next = NULL;
		}
	}	
	return head;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* pdelNode = head;
	ListNode* plast = head;
	ListNode* ptemp = NULL;
	
	//删除的是尾结点
	if(1 == n) {
		//只有一个节点
		if(NULL == head->next) {
			return NULL;
		}
		//不止一个节点 
		else {
			while(NULL != plast->next) {
				pdelNode = plast;
				plast = plast->next;
			}
			
			pdelNode->next = NULL;
			return head;
		}
	}
	else{
		//通过plast找到倒数第N个结点 
		for(int i = 0; i < n-1; i++) {
			plast = plast->next;
		}
		while(NULL != plast->next) {
			pdelNode = pdelNode->next;
			plast = plast->next;
		}
		
		//删除倒数第N个节点 
		ptemp = pdelNode->next;
		pdelNode->val =  pdelNode->next->val;
		pdelNode->next =  pdelNode->next->next;
		delete ptemp;
	}
}

//打印节点 
void printlist(ListNode* head) {
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
}

//释放内存 
void deletelist(ListNode* head) {
	ListNode* temp = NULL;
	while(NULL != head->next) {
		temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}

int main() {
	int a[] = {1,2,2,3,-1,1,4,5,-1};
	int n = 9;
	ListNode* head = init(a, n);
	removeNthFromEnd(head, 3);
	printlist(head);
	deletelist(head);
}


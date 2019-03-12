#include<iostream>
#include<cstring>
#include<map>
using namespace std;

typedef struct list {
	int data;
	list* next;
}list;

list* init(int a[], int n) {
	list *head, *last;
	for(int i= 0; i < n; i++) {
		list* node = new list;
		node->data = a[i];
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

//Map方式，时间复杂度O(n) 
void removelistdup1(list* head) {
	map<int, bool> dupnum;
	list *p = head, *q = head->next;
	dupnum.insert(map<int, bool>::value_type(p->data, true));
	while(q) {
		if(dupnum.find(q->data) != dupnum.end()) {
			list* temp = q;
			p->next = q->next;
			q = p->next;
			delete temp;
		}
		else {
			dupnum.insert(map<int, bool>::value_type(q->data, true));
			p = q;
			q = q->next;
		}
	}
}

//无额外记录方式，时间复杂度O(n^2) 
void removelistdup2(list* head) {
	list *p = head;
	while(p) {
		list *last = p, *q = p->next;
		while(q) {
			if(p->data == q->data) {
				list* temp = q;
				last->next = q->next;
				q = q->next;
				delete temp;
			}
			else {
				last = q;
				q = q->next;
			}
		}
		p = p->next;
	}
}

void printlist(list* head) {
	while(head) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main() {
	int a[] = {1,2,2,3,-1,1,4,5,-1};
	int n = 9;
	list* head = init(a,n);
	//removelistdup1(head);
	removelistdup2(head);
	printlist(head);
}

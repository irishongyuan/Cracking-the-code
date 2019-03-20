#include <iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
};

ListNode* init(int a[], int n) {
    ListNode *head = NULL, *last = NULL;
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

ListNode* reserveList1(ListNode* head) {
    ListNode* newhead, *pre;
    if(head->next == NULL){
        return head;
    }
    newhead = reserveList1(head->next);
    pre = head->next;
    pre->next = head;
    head->next = NULL;
    return newhead;
}

ListNode* reserveList2(ListNode* head) {
    ListNode* next = NULL;
    ListNode* pre = NULL;
    while(NULL != head) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

void printList(ListNode* head, int n){
    ListNode* node = head;
    while (n > 0) {
        cout << node->val << " ";
        node = node->next;
        n--;
    }
    cout << "end" << endl;
}

//int main() {
//    int a[] = {1,2,3,4,5,6};
//    int size = sizeof(a)/ sizeof(int);
//    ListNode* head = init(a, size);
//    printList(head, size);
//    ListNode* newhead = reserveList1(head);
//    printList(newhead, size);
//    ListNode* newhead2 = reserveList2(newhead);
//    printList(newhead2, size);
//    return 0;
//}

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *leftchild, *rightchild;
};

TreeNode* createNode(int val) {
	TreeNode* node = new TreeNode;
	node->leftchild = NULL;
	node->rightchild = NULL;
	node->val = val;
	return node;
}

//void insert(TreeNode **tree, int val) {
//	if(*tree == NULL) {
//		*tree = createNode(val);
//		return;
//	}
//	else if((*tree)->val >= val) {
//		return insert(&(*tree)->leftchild, val);
//	}
//	else {
//		return insert(&(*tree)->rightchild, val);
//	} 
//}

void insert(TreeNode* &tree, int val) {
	if(tree == NULL) {
		tree = createNode(val);
		return;
	}
	else if(tree->val >= val) {
		return insert(tree->leftchild, val);
	}
	else {
		return insert(tree->rightchild, val);
	} 
}

TreeNode* findNode(TreeNode* head, int val) {
	if(head == NULL) {
		return NULL;
	}
	else if(head->val == val) {
		return head;
	}
	else if(head->val >= val) {
		return findNode(head->leftchild, val);
	} 
	else {
		return findNode(head->rightchild, val);
	}
}

bool father(TreeNode* n1, TreeNode* n2) {
	if(n1 == NULL) {
		return false;
	}
	else if(n1 == n2) {
		return true;
	}
	else {
		return father(n1->leftchild, n2) || father(n1->rightchild, n2);
	}	
}

void first_ancestor(TreeNode* head, TreeNode* n1, TreeNode* n2, TreeNode* &ancnode) {
	if(head == NULL || n1 == NULL || n2 == NULL) {
		return;
	}
	if(head && father(head, n1) && father(head, n2)) {
		ancnode = head;
		first_ancestor(head->leftchild, n1, n2, ancnode);
		first_ancestor(head->rightchild, n1, n2, ancnode);
	}
	return;
}

void printTree(TreeNode *tree) {
	if(tree != NULL) {
		cout << tree->val << " ";
		printTree(tree->leftchild);
		printTree(tree->rightchild);
	}
}

void deleteTree(TreeNode *tree) {
	if(tree != NULL) {
		deleteTree(tree->leftchild);
		deleteTree(tree->rightchild);
		delete tree;
	}
}

int main() {
	TreeNode *tree = NULL;
	int a[] = {
		5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12
	};
	for(int i=0; i<12; ++i)
		insert(tree, a[i]);
		
	cout << "the tree is: ";
	printTree(tree);	
	cout << endl;
	
	TreeNode* n1 = findNode(tree, 1);
	TreeNode* n2 = findNode(tree, 2);
	
	TreeNode* ancnode = NULL;
	first_ancestor(tree, n1, n2, ancnode);
	cout << n1->val << " and " << n2->val << "'s father is" << ancnode->val << endl;
	
	deleteTree(tree);
}




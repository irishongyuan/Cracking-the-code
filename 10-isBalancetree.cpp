#include <iostream>
#include <cmath>
using namespace std; 

struct TreeNode {
	int value;
	TreeNode *leftchild, *rightchild;
};


TreeNode* createTreeNode(int val) {
	TreeNode *node = new TreeNode;
	node->value = val;
	node->leftchild = NULL;
	node->rightchild = NULL;
	
	return node;
}

void insert(TreeNode **tree,int val) {
	if(*tree == NULL) {
		cout << "createTreeNode:";
		*tree = createTreeNode(val);
		cout << *tree ;
		cout << (*tree)->value << endl;
		return;
	}
	else if((*tree)->value > val) {
		return insert(&(*tree)->leftchild, val);
	}
	else {
		return insert(&(*tree)->rightchild, val);
	}
}

int minDepth(TreeNode **tree) {
  if (*tree == NULL)
    return 0;
  if ((*tree)->leftchild == NULL && (*tree)->rightchild == NULL)
    return 1; //说明是个leaf了！
  int left = minDepth(&(*tree)->leftchild);
  int right = minDepth(&(*tree)->rightchild);
  return min(left, right) + 1;
}

int maxDepth(TreeNode **tree) {
  if (*tree == NULL)
    return 0;
  int left = maxDepth(&(*tree)->leftchild);
  int right = maxDepth(&(*tree)->rightchild);
  return max(left, right) + 1;
}

bool isBalanceTree(TreeNode **tree) {
	return (maxDepth(tree)-minDepth(tree)) <= 1;
}

void printTree(TreeNode **tree) {
	if(*tree != NULL) {
		cout << (*tree)->value << " ";
		printTree(&(*tree)->leftchild);
		printTree(&(*tree)->rightchild);
	}
}

void deleteTree(TreeNode **tree) {
	if(*tree != NULL) {
		deleteTree(&(*tree)->leftchild);
		deleteTree(&(*tree)->rightchild);
		delete *tree;
	}
}

int main() {
	TreeNode *treenode = NULL;
	TreeNode **tree = &treenode;
	int a[] = {
		5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12
	};
	for(int i=0; i<12; ++i)
		insert(tree, a[i]);
	printTree(tree);
	
	cout << (*tree)->rightchild << endl; 
	cout << *tree << endl;
	//cout << (*(*tree+5*sizeof(TreeNode*))).value << endl;
	
	cout << "max Depth is" << maxDepth(tree) << ",and min Depth is" << minDepth(tree) << endl;
	cout << "the tree is a balance tree?" << isBalanceTree(tree) << "(1--yes; 0--false)" << endl;
	
	deleteTree(tree);
}

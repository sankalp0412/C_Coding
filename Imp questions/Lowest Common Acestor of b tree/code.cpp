//here at any node i am calculating my reutnr/ans on the basis of my result
//from the lst and the rst hence we will use postorder

#include "bits/stdc++.h"
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val){
		this -> val =val;
		this -> left = NULL;
		this -> right = NULL;
	}
};

void init_code() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("output.txt", "w", stderr);
	#endif
}
TreeNode* findLowestCommonAncestor(TreeNode*root, TreeNode*p, TreeNode*q){
    if(!root) return NULL;
    if(root == p) return p;
    if(root == q) return q;

    TreeNode * lst = findLowestCommonAncestor(root -> left, p ,q);
    TreeNode * rst = findLowestCommonAncestor(root -> right, p ,q);
    
    if(!lst && !rst) return NULL;
    else if(lst && rst) return root;
    else if(lst) return lst;
    else return rst;     
   }

int main() {
	init_code();
	TreeNode *root = new TreeNode(3);
	root -> left = new TreeNode(5);
	root -> right = new TreeNode(1);
	root -> left -> left = new TreeNode(6);
	root -> left -> right = new TreeNode(2);
	root -> left -> right -> left = new TreeNode(7);
	root -> left -> right -> right = new TreeNode(4);
	root -> right -> left = new TreeNode(0);
	root -> right -> right = new TreeNode(8);

	TreeNode *ans = findLowestCommonAncestor(root,root -> left -> left, root -> left -> right -> right);
	cout << ans->val;

	return 0;
}
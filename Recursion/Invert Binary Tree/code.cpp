#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

struct TreeNode
{
	int val;
	TreeNode* right;
	TreeNode* left;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution
{
public:
	 TreeNode * invertTree(TreeNode *root) {
	 	if(!root) return NULL;
	 	if(!root -> left && !root -> right) return root;
	 	TreeNode *temp = root -> left;        
	 	root -> left = invertTree(root -> right);
	 	root -> right = invertTree(temp);
	 	return root;
	 }
	
};

int main() {
	init_code();
	// cout << "Enter the tree value space separated";
	TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution solution;

    TreeNode* invertedRoot = solution.invertTree(root); 
    std::cout << "Inverted tree: ";
    std::cout << invertedRoot->val << " ";
    std::cout << invertedRoot->left->val << " ";
    std::cout << invertedRoot->right->val << " ";
    std::cout << invertedRoot->left->left->val << " ";
    std::cout << invertedRoot->left->right->val << " ";
    std::cout << invertedRoot->right->left->val << " ";
    std::cout << invertedRoot->right->right->val << std::endl;
	return 0;
}

///HERE AT LINE 29 FIRST I DIDNT USE THE TEMP NODE, SO DURING THE RECURSION CALL WHEN 
//THE LEFT CHILD WAS BEING INITALLZED WITH THE RIGHT CHILD AND WHEN IT
// COMES BACK THE LEFT CHILD IS ACTUALLY THE RIGH CHILD NOW
// SO THE SATEMENT 	root -> right = invertTree(root -> left );
//is same as calling 	root -> right = invertTree(root-> right);
//hence we have to use a temp pointer holding the left subtree.
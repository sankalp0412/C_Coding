//IMPORTANT FOR POST ORDER TRAVERSAL
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* solve (TreeNode* root, unordered_set<int> &s, vector<TreeNode*> &vec) {
        if(!root) return NULL;
        auto lst = solve(root -> left, s,vec);
        auto rst = solve(root -> right,s,vec);

        if(s.count(root -> val)){
            if(lst)vec.push_back(lst);
            if(rst) vec.push_back(rst);
            return NULL;
        }

        root -> left= lst;
        root -> right =rst;
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> vec;
        unordered_set<int> s;
        for(auto &x: to_delete) s.insert(x);
        root = solve(root,s,vec);
        if(root) vec.push_back(root);
        return vec;
    }
};
int main() {
	init_code();
	auto root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);
	root -> left -> left = new TreeNode(4);
	root -> left -> right = new TreeNode(5);
	root -> right -> left = new TreeNode(6);
	root -> right -> right = new TreeNode(7);
	Solution sol;
	vector<int> to_delete = {3,5};
	auto vec = sol.delNodes(root,to_delete);
	for(auto it: vec) {
		cout << it -> val << " ";
	}
	return 0;
}
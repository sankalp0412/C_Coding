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
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    //better using O(1) space:
    // void dfs(TreeNode* root , int k, int &ans, int &cnt) {
    //     if (!root )return;
    //     dfs(root -> left,k,ans,cnt);
    //     cnt += 1;
    //     if(cnt == k) {
    //         ans = root -> val;
    //         return ;
    //     }
    //     dfs(root -> right,k,ans,cnt);
    // } 
    // int kthSmallest(TreeNode* root, int k) {
    //     int ans = -1, cnt= 0;
    //     dfs(root, k,ans,cnt);
    //     return ans;
    // }
class Solution {
public:
    void fn(TreeNode* root, vector<int> &inorder) {
        if(!root) return;
        fn(root -> left, inorder);
        inorder.push_back(root -> val);
        fn(root -> right, inorder);

        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        fn(root, inorder);
        return inorder[k-1];
    }

    int kthSmallesIterative(TreeNode* root ,int k) {
        stack<TreeNode*> st;
        int n = 0;
        auto curr = root;
        while(curr && !st.empty()) {
            while(curr) {
                st.push(curr); 
                curr = curr -> left;
            }
            curr = st.top();
            st.pop();
            n += 1;
            if( n== k) 
                return curr -> val;

            curr = curr -> right;
        }

    return -1;
    }
};
int main() {
	init_code();
    // Define the structure of a TreeNode
   

    // Create the tree root = [3,1,4,null,2]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 1; // k = 1

    Solution sol;
    int ans = sol.kthSmallest(root,k);
    cout << ans;
	return 0;
}
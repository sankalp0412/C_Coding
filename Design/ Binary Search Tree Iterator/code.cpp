#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
//First code


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class BSTIterator {
// public:
//     vector<int> inorder;
//     int curr_pos = -1;
//     void get_inorder(TreeNode *root) {
//         if(!root) return;
//         get_inorder(root -> left);
//         this -> inorder.push_back(root -> val);
//         get_inorder(root -> right);
//     }
//     BSTIterator(TreeNode* root) {
//         get_inorder(root);
//     }
    
//     int next() {
//         this -> curr_pos++;
//         return this -> inorder[curr_pos];
//     }
    
//     bool hasNext() {
//         return this -> curr_pos + 1 < this-> inorder.size();
        
//     }
// };

//TC: of constructor = O(n) and 
//SC: O(n)
//Question demanded and overall space complexity of O(h)



//Better code, the idea  is to use lazy travesing
//here at max each time we are addig lelement in the stack max height of hte tree, we are going all the way down one verical time
 


class BSTIterator {
public:
    stack<TreeNode*> st;

    void pushLeft(TreeNode*node) {
        while(node){
            st.push(node);
            node = node -> left;
        }
    }
  
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode *curr = st.top();
        st.pop();
        pushLeft(curr -> right);
        return curr -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

int main() {
	init_code();
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
//Pre order traversal
//The idea is to keep the frequency of digit 1 in the first bit, 
// 2 in the second bit, etc: path ^= (1 << node.val).
//  Hence, one could see the bit in a path only if it appears an odd number of times.

//Line 32 
// to ensure that at most one digit has an odd frequency, one has 
// to check that path is a power of two, i.e., at most one bit is set to one

// bit representation of 7  -> 0111
// bit representation of 8  -> 1000
// bitwise AND of 7 and 8 -> 0000
// we are gonna use this property for for all numbers which are 
// powers of two



// Definition for a binary tree node.
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
    void solve(TreeNode *root, int pathBitVal, int &ans) {
        if(!root) return;
        pathBitVal ^= (1 << root -> val);
        if(!root -> left && !root -> right){
            if((pathBitVal & (pathBitVal - 1)) == 0)
                ans++;
        }

        solve(root -> left, pathBitVal, ans );
        solve(root -> right, pathBitVal, ans );
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        solve(root, 0,ans);
        return ans; 
    }
};
int main() {
	init_code();
	TreeNode *root = new TreeNode(2);
	root -> left = new TreeNode(3);
	root -> left -> left = new TreeNode(3);
	root -> left -> right = new TreeNode(1);
	root -> right = new TreeNode(1);
	root -> right -> right = new TreeNode(1);
	Solution sol;
	cout << sol.pseudoPalindromicPaths(root);
	return 0;
}
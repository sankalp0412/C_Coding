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
    bool dfs(TreeNode* root, int &rval, string &path) {
        if(!root) return false;
        if(root -> val == rval) return true;

        path += 'L';
        if(dfs(root -> left,rval,path)) return true;
        path.pop_back();

        path += 'R';
        if(dfs(root -> right,rval,path)) return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        dfs(root, startValue, pathToStart);
        dfs(root, destValue, pathToDest);
        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            i++;
        }
        string ans(pathToStart.size() - i, 'U');
        ans += pathToDest.substr(i);
        return ans;
    }
};

TreeNode* createTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
	init_code();
	vector<int> nodes = {1, -1, 10, 12, 13, 4, 6, -1, 15, -1, -1, 5, 11, -1, 2, 14, 7, -1, 8, -1, -1, -1, 9, 3};
    int startValue = 6;
    int destValue = 15;
    TreeNode* root = createTree(nodes);
	Solution sol;
	cout << sol.getDirections(root,startValue,destValue);
	return 0;
}


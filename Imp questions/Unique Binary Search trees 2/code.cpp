#include "bits/stdc++.h"
using namespace std;

// #define for(i,n) for(int i = 0; i < n; i++)

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
//Function and map declarations
unordered_map<string, vector<TreeNode*>> mp;
TreeNode *clone(TreeNode*,int);
vector<TreeNode*> dpSpaceOptimal(int);

//////////////////////////////
//O(n^2) + O(n^2)
//The number of recursive calls at each level decreases as the tree size reduces, 
// but the overall time complexity is still dominated by the O(n^2) term.
vector<TreeNode*> solveRecursion(vector<int> tree) {
        vector<TreeNode*> arr;
        if (tree.empty()) {
            arr.push_back(nullptr);
            return arr;
        }
        for (int i = 0; i < tree.size(); i++) { // O(n)
            vector<int> lst(tree.begin(), tree.begin() + i);
            vector<int> rst(tree.begin() + i + 1, tree.end()); // O(n)
            auto leftTreeNodes = solveRecursion(lst);
            auto rightTreeNodes = solveRecursion(rst);

            for (auto Lnode : leftTreeNodes) {
                for (auto Rnode : rightTreeNodes) {
                    auto currRoot = new TreeNode(tree[i]);
                    currRoot->left = Lnode;
                    currRoot->right = Rnode;
                    arr.push_back(currRoot);
                }
            }
        }
        return arr;
    }

    vector<TreeNode*> solveMemo(vector<int> tree) {
        vector<TreeNode*> arr;
        if (tree.empty()) {
            arr.push_back(nullptr);
            return arr;
        }
        string str;
        for(auto it: tree) str += to_string(it);
        if(mp.find(str) != mp.end()) return mp[str];
        for (int i = 0; i < tree.size(); i++) {
            vector<int> lst(tree.begin(), tree.begin() + i);
            vector<int> rst(tree.begin() + i + 1, tree.end());
            auto leftTreeNodes = solveMemo(lst);
            auto rightTreeNodes = solveMemo(rst);

            for (auto Lnode : leftTreeNodes) {
                for (auto Rnode : rightTreeNodes) {
                    auto currRoot = new TreeNode(tree[i]);
                    currRoot->left = Lnode;
                    currRoot->right = Rnode;
                    arr.push_back(currRoot);
                }
            }
        }
        return mp[str] = arr;
    }

vector<TreeNode*> solveIterative(int n) {
     vector<vector<vector<TreeNode*>>> dp(n + 1, vector(n + 1, vector<TreeNode*>(0)));
        for (int i = 1; i <= n; i++) {
            dp[i][i].push_back(new TreeNode(i));
        }

        for (int numberOfNodes = 2; numberOfNodes <= n; numberOfNodes++) {
            for (int start = 1; start <= n - numberOfNodes + 1; start++) {
                int end = start + numberOfNodes - 1;
                for (int i = start; i <= end; i++) {
                    vector<TreeNode*> leftSubtrees =
                        i - 1 >= start ? dp[start][i - 1] : vector<TreeNode*>({NULL});
                    vector<TreeNode*> rightSubtrees =
                        i + 1 <= end ? dp[i + 1][end] : vector<TreeNode*>({NULL});

                    for (auto left : leftSubtrees) {
                        for (auto right : rightSubtrees) {
                            TreeNode* root = new TreeNode(i, left, right);
                            dp[start][end].push_back(root);
                        }
                    }
                }
            }
        }
        return dp[1][n];
}
 vector<TreeNode*> generateTrees(int n) {
        vector<int> tree(n);
        for (int i = 0; i < n; i++) tree[i] = i + 1;
        // return solveIterative(n);
        return dpSpaceOptimal(n);
    }

void dfs(TreeNode *root) {
	if(!root) {
		cout << "NULL" << ",";
		return;
	}
	cout << root -> val << ",";
	dfs(root -> left);
	dfs(root -> right);
}    
int main() {
	init_code();
	int n ;
	cin >> n;
	auto ans = generateTrees(n);
	for(auto node: ans) {
		dfs(node);
		cout << endl << "===" << endl;
	}
	return 0;
}


//Space Optimization
vector<TreeNode*> dpSpaceOptimal(int n) {
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0].push_back(NULL);

        for (int numberOfNodes = 1; numberOfNodes <= n; numberOfNodes ++) {
            for (int i = 1; i <= numberOfNodes; i ++) {
                int j = numberOfNodes - i;
                for (auto left : dp[i - 1]) {
                    for (auto right : dp[j]) {
                        TreeNode* root = new TreeNode(i, left, clone(right, i));
                        dp[numberOfNodes].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }
 TreeNode* clone(TreeNode* node, int offset) {
        if (node == NULL) {
            return NULL;
        }
        TreeNode* clonedNode = new TreeNode(node->val + offset);
        clonedNode->left = clone(node->left, offset);
        clonedNode->right = clone(node->right, offset);
        return clonedNode;
    }
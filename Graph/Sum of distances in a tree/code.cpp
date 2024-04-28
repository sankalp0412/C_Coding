/*There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes. */


//Theroy : child_ans = parent_ans - (no of childred of child including child (x)) + rem_nodes (n-x); 
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}	
class Solution {
public:
    long root_res = 0;
    vector<int> count;
    int N;
    int dfsRoot(vector<int> adj[], int u, int prev, int currDepth) {
        int total_count = 1;

        root_res += currDepth;
        for(int &v: adj[u]) {
            if(v != prev) 
                total_count += dfsRoot(adj, v, u, currDepth + 1);
            
        }

        count[u] = total_count;
        return total_count;
    } 
    
    void dfs(vector<int> adj[], int u, int prev, vector<int> &res) {
        for(int &v: adj[u]) {
            if(v != prev)  {
                res[v] = res[u] - count[v] + (N - count[v]);
                dfs(adj, v, u, res);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        N=n;
        count.resize(N,0);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }       
        dfsRoot(adj,0, -1, 0);  

        vector<int> res(n,0);
        res[0] = root_res;

        dfs(adj,0,-1,res);

        return res;      
    }
};
int main() {
	init_code();
	int n = 6;
	vector<vector<int> > edges = {{0,1}, {0,2}, {2,3}, {2,4}, {2,5}};
	Solution sol;
	vector<int> ans = sol.sumOfDistancesInTree(n,edges);
	for(auto x: ans) cout << x << ",";
	return 0;
}
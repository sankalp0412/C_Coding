/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 
*/

//Brute force will be to check by making all n nodes roots one by one.
//so that will be O(n) * O(E+V) (Traversal TC), but since edges are almost
// equal to n (n-1) so it will be O(n^2);
//https://www.youtube.com/watch?v=wQGQnyv_9hI
//The outer most nodes with only one edge cannot be the root nodes
//https://www.youtube.com/watch?v=ZXANlaEuYvQ

//Leaf can never be the answer
//ans will either be 1 or 2 can never be more than 2
// Answer will be the central nodes.
//hence we will start rejecting from the leaf nodes towards the center

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	unordered_map<int,vector<int>> adj;
	vector<int> indegree(n);

	for(auto& edge: edges) {
		int u = edge[0];
		int v = edge[1];
		indegree[u]++;
		indegree[v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> ans;

	queue<int> q;
	for(int i = 0; i < n; i++) {
		if(indegree[i] == 1) 
			q.push(i); //leaf nodes
	}

	while(n > 2) {
		int size = q.size();
		n -= size;

		while(size--) {
			int u = q.front();
			q.pop();

			for(auto &v: adj[u]) {
				indegree[v]--;
				if(indegree[v] == 1){
					q.push(v);
				}
			}
		}
	}

	while(!q.empty()) {
		ans.push_back(q.front());
		q.pop();
	}
	return ans;
}
int main() {
	init_code();
	int n = 6;
	vector<vector<int>> graph = {{3,0}, {3,1}, {3,2}, {3,4}, {5,4}};
	vector<int> ans = findMinHeightTrees(n,graph);
	for(auto x: ans) cout << x << ",";
	return 0;
}
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
class Solution{
	public:
	#define pii pair<int,int>
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V,0);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,0});
        int ans = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]= 1;
            ans += wt;
            for(auto it: adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];
                if(!vis[adjNode]) {
                    pq.push({edgeWt,adjNode});
                }
            }
        }
    return ans;
    }
};
int main() {
	init_code();
	int V,n;
	cin >> V >> n;
	vector<vector<int>> adj[n];
	for(int i = 0; i < n; i++) {
		int u,v,wt;
		cin >> u >> v >> wt;
		adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
	}
	Solution solution;
	cout << solution.spanningTree(V,adj);
	return 0;
}
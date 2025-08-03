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
    vector<int> getTopoOrder(vector<int> &indegree, vector<vector<pair<int,int>>> &graph, int &n) {
        //Kahn's algorithm
        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < n; i++) {
            if(!indegree[i])
                q.push(i);
        } //O(n)

        while(!q.empty()) { //O(V) - number of vertices
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for(auto &adj: graph[u]) { //O(m)
                int v = adj.first;
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return topo;
    }
    bool isPossible(vector<vector<pair<int,int>>> &graph, long long k, int m, vector<int> &topo, int &n) {
        vector<long long> dist(n,k+1);
        dist[0] = 0;

        for(auto &u : topo) {
            for(auto & adjNode: graph[u]) {
                int v = adjNode.first;
                int w = adjNode.second;

                if(w >= m && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        return dist[n-1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> graph(n); //O(n)
        vector<int> indegree(n,0);
        int left = INT_MAX;
        int right = INT_MIN;
        for(auto &edge : edges) { //O(m) - m numbe of edges
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            
            if(!online[u] || !online[v]) continue;

            left = min(left,cost);
            right = max(right,cost);
            
            indegree[v]++;
            graph[u].push_back({v,cost});
        }

        vector<int> topo = getTopoOrder(indegree,graph,n); //O(n+m)
        int ans = -1;
        while(left <= right) { //O(log c)
            int mid = left + (right - left) /2;
            if(isPossible(graph,k,mid,topo,n)) { //O(n+m)
                ans = mid;
                left = mid + 1;
            }
            else 
                right = mid - 1;
        }

        return ans;
    }
};

int main() {
    init_code();
    vector<vector<int>> edges = {{0,1,5},{1,3,10},{0,2,3},{2,3,4}};
    vector<bool> online = {true,true,true,true};
    long long k = 10;
    Solution sol;
    int result = sol.findMaxPathScore(edges, online, k);
    cout << "Max Path Score: " << result << endl;
    return 0;
}

/* Time Complexity
Building the graph and indegree array: O(m), where m = number of edges.
Topological sort (getTopoOrder): O(n + m), where n = number of nodes.
Binary search loop: O(log C), where C = range of edge costs (from min to max).
For each binary search iteration, isPossible runs a relaxation over all edges in topological order: O(n + m).

Space Complexity
Graph storage: O(n + m)
Indegree array: O(n)
Topological order: O(n)
Distance array in isPossible: O(n)
So, total space complexity: O(n + m)




*/
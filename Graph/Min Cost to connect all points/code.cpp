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
    long long manhattan(int x1, int y1, int x2, int y2) {
        return abs(x1-x2) + abs(y1-y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> graph[n];
        for(int i = 0; i < n ; i++) {
            for(int j = i+1; j < n; j++) {
                long long weight = manhattan(points[i][0],points[i][1], points[j][0], points[j][1]);
                graph[i].push_back({j,weight});
                graph[j].push_back({i,weight});
            }
        }
        vector<int> vis(n,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0}); 
        long long sum = 0;
        while(!pq.empty()) {
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            sum += wt;
            

            for(auto &adj: graph[u]) {
                int adjNode = adj.first;
                int adjWt = adj.second;
                if(!vis[adjNode]) {
                    pq.push({adjWt,adjNode});
                }
            }
        }
        return sum;
    }
};
int main() {
	init_code();
    vector<vector<int>> points =  {{0,0},{2,2},{3,10},{5,2},{7,0}};
    Solution sol;
    cout << sol.minCostConnectPoints(points);
    return 0;
}
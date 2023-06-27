// time complexotu: there are n nodes and for each i amtrying to place m colors
// n to tthe power m
// SC: O(n) to color and aux space O(n) : O(N)
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isPossible(int node, int n, int color[],bool graph[101][101] , int col) {
        for(int i = 0; i < n; i++) {
            if(i != node && graph[i][node] == 1 && color[i] == col )
                return false;
        }
        return true;
    }
    bool solve(int node, int n, int m, int colors[], bool graph[101][101]) {
        if(node == n)
            return true;
        for(int i = 1; i <= m; i++) {
            if(isPossible(node,n,colors,graph,i))
            colors[node] = i;
            if(solve(node+1,n,m,colors,graph))
                return true;
            colors[node] = 0;
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
       int colors[n] = {0};
       return solve(0,n,m,colors,graph);
    }
};

//{ Driver Code Starts.

int main() {
	init_code();
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

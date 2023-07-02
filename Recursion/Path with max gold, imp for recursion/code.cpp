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
    int dfs(int i, int j, vector<vector<int>> &g, vector<vector<int>> &vis, int n, int m) {
        if(i < 0 || i == n || j < 0 || j == m || !g[i][j] || vis[i][j]) return 0;
        vis[i][j] = 1;
        int ans = g[i][j] + max({dfs(i - 1, j, g, vis, n, m), dfs(i + 1, j, g, vis, n, m),
                             dfs(i, j - 1, g, vis, n, m), dfs(i, j + 1, g, vis, n, m)});
        vis[i][j] = 0;
        return ans;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]) {
                    vector<vector<int>> vis(n, vector<int>(m));
                    ans = max(ans, dfs(i, j, grid, vis, n, m));
                }
            }
        }
        return ans;
    }
};
int main() {
	init_code();
	Solution solution;
	vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
	cout << solution.getMaximumGold(grid);
	return 0;
}
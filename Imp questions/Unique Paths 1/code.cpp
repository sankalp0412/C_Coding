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
class Solution {
public:
	int solveMemo(int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = solveMemo(i-1, j, dp);
        int left = solveMemo(i, j-1, dp);

        return dp[i][j] = up + left;
    }
	int solveTabulation(int m, int n) {
		vector<vector<int> > dp(m,vector<int> (n,0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                vector<vector<int> > directions = {{-1,0}, {0,-1}};
                for(auto dir: directions) {
                    int xi = i + dir[0];
                    int xj = j + dir[1];
                    if(xi >= 0 && xj >= 0 && xi < m && xj < n) {
                        dp[i][j] += dp[xi][xj];
                    }
                }
            }
        } 
        return dp[m-1][n-1];
	}
    int uniquePaths(int m, int n) {
        // return solveTabulation(m,n);
        vector<vector<int>> dp(m, vector<int>(n, -1));
       	return solveMemo(m,n,dp);
    }
};

int main() {
	init_code();
	int m,n;
	cin >> m >> n;
	Solution solution;
	cout << solution.uniquePaths(m,n);
	return 0;
}
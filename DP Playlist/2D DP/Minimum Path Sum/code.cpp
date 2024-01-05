#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int memo[201][201];
    long solve(int i, int j, vector<vector<int>> &grid, int &m, int &n) {
        //base
        if(i == m - 1 && j == n - 1)
            return grid[m-1][n-1];

        if(i >= m || j >= n)
            return INT_MAX;       //This case has to return something so that this path is not included for our answer, generally if we are trying to find minimum we will return a large value    
        

        if(memo[i][j] != -1)
            return memo[i][j];
        long down = 0, right = 0;
        down = grid[i][j] + solve(i + 1,j,grid,m,n);
        right = grid[i][j] + solve(i,j+1,grid,m,n);

        return memo[i][j] = min(down,right);        
}
int solveTabulation(vector<vector<int>> grid) {
	int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int> (n,0));
    for(int i = 0; i < m; i++) {
    	for(int j = 0; j < n; j++) {
    		if(i == 0 && j == 0)
    			dp[i][j] = grid[i][j];
    		else {
    			int up = INT_MAX, left = INT_MAX;
    			if(i > 0) up = grid[i][j] + dp[i-1][j];
    			if(j > 0) left = grid[i][j] + dp[i][j-1]; 
    			dp[i][j] = min(up,left);
    		}
    	}
    }
    return dp[m-1][n-1];
}
int solveSpaceOptimized(vector<vector<int>> &grid) {
	int n = grid[0].size();
        int m = grid.size();
        vector<int> prevDp(n,0);
        for(int i = 0; i < m; i++) {
            vector<int> curr(n,0);
        	for(int j = 0; j < n; j++) {
        		if(i == 0 && j == 0)
        			curr[j] = grid[i][j];
        		else {
        			int up = INT_MAX, left = INT_MAX;
        			if(i > 0) up = grid[i][j] + prevDp[j];
        			if(j > 0) left = grid[i][j] + curr[j-1]; 
        			curr[j] = min(up,left);
        		}
        	}
            prevDp = curr;
        }
        return prevDp[n-1];
}
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    memset(memo,-1,sizeof(memo));
    // return (int)solve(0,0,grid,m,n);
    // return solveTabulation(grid);
    return solveSpaceOptimized(grid);
}
int main() {
	init_code();
	vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
	cout << minPathSum(grid);
	return 0;
}
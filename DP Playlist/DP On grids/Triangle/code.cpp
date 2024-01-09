#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int solveMemo(vector<vector<int>>& triangle, int row, int col,vector<vector<int> > &memo) {
        if(row == 0)
            return triangle[0][0];
        
        if(memo[row][col] != -1)
            return memo[row][col];
        int rowLen = triangle[row].size();

        int upLeft = INT_MAX, upRight = INT_MAX;
        if(col > 0)          upLeft = solveMemo(triangle, row - 1, col - 1,memo);
        if(col < rowLen - 1) upRight = solveMemo(triangle, row - 1, col,memo);

        return memo[row][col] = triangle[row][col] + min(upLeft,upRight);
}
int solveTabulation(vector<vector<int>>& triangle){
	int n = triangle.size();
    vector<vector<int> > dp(n,vector<int> (n,-1));
    dp[0][0] = triangle[0][0];
    for(int row = 1; row < n; row++) {
    	int rowLen = triangle[row].size();
    	for(int col = 0; col < rowLen; col++) {
    		int upLeft = INT_MAX, upRight = INT_MAX;
        	if(col > 0)          upLeft = dp[row - 1][col - 1];
        	if(col < rowLen - 1) upRight = dp[row - 1][col];

        	dp[row][col] = triangle[row][col] + min(upLeft, upRight);
    	}
    }

    int ans = INT_MAX;
    for(int j = 0; j < triangle[n-1].size(); j++)
    	ans = min(ans, dp[n-1][j]);

    return ans;
}
int solveSpaceOptimization(vector<vector<int>>& triangle){
	int n = triangle.size();
        vector<int> prevDp(triangle[0].size());
        // vector<vector<int> > dp(n,vector<int> (n,-1));
        prevDp[0] = triangle[0][0];
        for(int row = 1; row < n; row++) {
    	    int rowLen = triangle[row].size();
            vector<int> newDp(rowLen);
    	    for(int col = 0; col < rowLen; col++) {
    		    int upLeft = INT_MAX, upRight = INT_MAX;
        	    if(col > 0)          upLeft = prevDp[col - 1];
        	    if(col < rowLen - 1) upRight = prevDp[col];

        	    newDp[col] = triangle[row][col] + min(upLeft, upRight);
    	    }
            prevDp = newDp;
        }

    int ans = INT_MAX;
    for(int j = 0; j < triangle[n-1].size(); j++)
    	ans = min(ans, prevDp[j]);

    return ans;
}
int minimumTotal(vector<vector<int>>& triangle) {
	return solveSpaceOptimization(triangle);
	return solveTabulation(triangle);
    int n = triangle.size();
    vector<vector<int> > memo(n,vector<int> (n,-1)); 
    int ans = INT_MAX;
    for(int j = 0; j < triangle[n-1].size(); j++)
        ans = min(ans, solveMemo(triangle, n-1, j,memo));
    return ans;
    }
int main() {
	init_code();
	vector<vector<int>> triangle = {{2},{3,4}, {6,5,7},{4,1,8,3}};
	cout << minimumTotal(triangle);
	return 0;
}

//TC and SC for Recursion
// TC: O(N*N) ; not exactly n*n as it's a triangle
// SC: O(N) which is the Recursion stack space.

//For Tabulation
//TC: Same
// SC: O(N*N) for the matrix

// After Space optimization
// SC: O(N)
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int spaceOptimization(vector<vector<int>>& matrix) {
	 int ans = INT_MAX;
        int m = matrix.size(), n = matrix[0].size();

        vector<int> prevDp(m,0);

        //base
        for(int i = 0; i < n; i++) 
            prevDp[i] = matrix[0][i];
        
        for(int i = 1; i < m; i++) {
            vector<int> newDp(m,0);
            for(int j = 0; j < n; j++) {
                int down, ld = INT_MAX, rd = INT_MAX;
                if(j > 0)
                    ld = matrix[i][j] + prevDp[j-1];
                if(j < matrix[i].size() - 1)
                    rd = matrix[i][j] + prevDp[j+1];
        
                down = matrix[i][j] + prevDp[j];

                newDp[j] = min(ld, min(down, rd));
            }
            prevDp = newDp;
        }
        for(int j = 0; j <n; j++)
            ans = min (ans, prevDp[j]);
        
        return ans;
}
int solveTablation(vector<vector<int>>& matrix) {
	int ans = INT_MAX;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp (m,vector<int> (n,0));

        //base
        for(int i = 0; i < n; i++) 
            dp[0][i] = matrix[0][i];
        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int down, ld = INT_MAX, rd = INT_MAX;
                if(j > 0)
                    ld = matrix[i][j] + dp[i-1][j-1];
                if(j < matrix[i].size() - 1)
                    rd = matrix[i][j] + dp[i-1][j+1];
        
                down = matrix[i][j] + dp[i-1][j];

                dp[i][j] = min(ld, min(down, rd));
            }
        }
        for(int j = 0; j <n; j++)
            ans = min (ans, dp[m-1][j]);
        
        return ans;
}
int solveMemo(int row, int col, vector<vector<int>>& matrix, vector<vector<int>> &memo) {
        if(row == 0)
            return matrix[row][col];

        if(memo[row][col] != -1)
            return memo[row][col];
        
        int down, ld = INT_MAX, rd = INT_MAX;

        if(col > 0)
            ld = matrix[row][col] + solveMemo(row - 1, col - 1, matrix, memo);
        if(col < matrix[row].size() - 1)
            rd = matrix[row][col] + solveMemo(row - 1, col + 1 , matrix, memo);
        
        down = matrix[row][col] + solveMemo(row - 1, col, matrix, memo);

        return memo[row][col] = min(ld, min(down, rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
    	return spaceOptimization(matrix);
    	return solveTablation(matrix);
        int ans = INT_MAX;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo (m,vector<int> (n,-1));
        for(int j = 0; j < n; j++){
            ans = min(ans,solveMemo(m-1, j, matrix, memo));
        }
        return ans;
    }
int main() {
	init_code();
	vector<vector<int>> grid = {{2,1,3}, {6,5,4}, {7,8,9}};
	cout << minFallingPathSum(grid);
	return 0;
}
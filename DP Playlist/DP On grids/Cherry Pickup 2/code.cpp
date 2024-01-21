//In this question we have a fixd starting point and a variable ending point
//Generally in these type of questions we write the recursion from the starting
// point 
//TC of normal recursion 3^n * 3^n 
//SC is aux stack space O(n) 

//TC of memo O(m*N*N) * 9
//SC is O(M*N*N) + O(n)

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 int solveMemo(int i, int j1, int j2, int &m, int &n,vector<vector<int>>& grid,vector<vector<vector<int>>> &memo) {
        //base cases
        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n) 
            return -1e8;

        if(i == m - 1){
            if(j1 == j2)
                return grid[i][j1];
            else 
                return grid[i][j1] + grid[i][j2];
        }

        if(memo[i][j1][j2] != -1)
            return memo[i][j1][j2];
        //For every direction of robot 1 we have three possible directions of robot 2
        int res = INT_MIN;
        for(int nj1 = -1; nj1 <= 1; nj1++){
            for(int nj2 = -1; nj2 <= 1; nj2++) {
                if(j1 == j2) 
                    res = max(res, grid[i][j1] + solveMemo(i + 1, j1 + nj1, j2 + nj2,m,n,grid,memo));
                else 
                    res = max(res, grid[i][j1] + grid[i][j2] + solveMemo(i + 1, j1 + nj1, j2 + nj2,m,n,grid,memo));
            }
        }  
        return memo[i][j1][j2] = res;
    }
int solveTabulation(vector<vector<int>> & grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (n,-1))); 
    //base
    for(int j1 = 0; j1 < n; j1++) 
        for(int j2 = 0; j2 < n; j2++) {
            if(j1 == j2)
                dp[0][j1][j2] = grid[0][j1];
            else 
                dp[0][j1][j2] = grid[0][j1] + grid[0][j2];
        }

    for(int i = 1; i < m; i++) {
        for(int j1 = 0; j1 < n; j1++){
            for(int j2 = 0; j2 < n; j2++) {
                int maxi = INT_MIN;
                for(int nj1 = -1; nj1 <= 1; nj1++){
                    for(int nj2 = -1; nj2 <= 1; nj2++) {
                        int val = 0;
                        if(j1 == j2) 
                            val = grid[i][j1];
                        else 
                            val = grid[i][j1] + grid[i][j2];
                        if(j1 + nj1 >= 0 && j1 +nj1 < n && j2 + nj2  >= 0 && j2 + nj2 < n) 
                            val += dp[i-1][j1 + nj1][j2 + nj2];
                        else 
                            val += -1e8;
                        maxi = max(maxi,val);     
                    }
                }  
                dp[i][j1][j2] = maxi;
            }
        }
    }
    int res = INT_MIN;
    for (int j1 = 0; j1 < n; ++j1) {
        for (int j2 = 0; j2 < n; ++j2) {
            res = max(res, dp[n - 1][j1][j2]);
        }
    }
    return res ;
}
int solveSpaceOptimization(vector<vector<int>> &grid ) {
    //thi is a 3d dp so space optimization will change it to one dp down i.e. 2d dp
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> prevDp(n,vector<int>(n,0));
    vector<vector<int>> currDp(n,vector<int>(n,0));

    //base
    for(int j1 = 0; j1 < n; j1++) 
        for(int j2 = 0; j2 < n; j2++) {
            if(j1 == j2)
                prevDp[j1][j2] = grid[0][j1];
            else 
                prevDp[j1][j2] = grid[0][j1] + grid[0][j2];
        }

    for(int i = 1; i < m; i++) {
        for(int j1 = 0; j1 < n; j1++){
            for(int j2 = 0; j2 < n; j2++) {
                int maxi = INT_MIN;
                for(int nj1 = -1; nj1 <= 1; nj1++){
                    for(int nj2 = -1; nj2 <= 1; nj2++) {
                        int val = 0;
                        if(j1 == j2) 
                            val = grid[i][j1];
                        else 
                            val = grid[i][j1] + grid[i][j2];
                        if(j1 + nj1 >= 0 && j1 +nj1 < n && j2 + nj2  >= 0 && j2 + nj2 < n) 
                            val += prevDp[j1 + nj1][j2 + nj2];
                        else 
                            val += -1e8;
                        maxi = max(maxi,val);     
                    }
                }  
                currDp[j1][j2] = maxi;
            }
        }
        prevDp = currDp;
    }
    int res = INT_MIN;
    for (int j1 = 0; j1 < n; ++j1) {
        for (int j2 = 0; j2 < n; ++j2) {
            res = max(res, prevDp[j1][j2]);
        }
    }
    return res ;
}
int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> memo(m,vector<vector<int>> (n,vector<int> (n,-1))); 
    // return solveMemo(0,0,n-1,m,n,grid,memo);
    // return solveTabulation(grid);
    return solveSpaceOptimization(grid);
}
int main() {
	init_code();
	vector<vector<int>> grid = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
	cout << cherryPickup(grid);
	return 0;
}
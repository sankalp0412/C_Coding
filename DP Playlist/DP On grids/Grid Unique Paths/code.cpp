#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int memo[101][101];
    int solveMemo(int i, int j, int &m, int &n) {
        if(i == m - 1 && j == n - 1)
            return 1;
        if(i >= m || j >= n)
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];
        int moveDown,moveRight;
        moveDown = solveMemo(i + 1,j,m,n);
        moveRight = solveMemo(i,j+1,m,n);

        return memo[i][j] = moveRight + moveDown;
    }
int solveTabulation(int m, int n) {
        int dp[101][101]; //dp[i][j] defines the number of ways to reach the cell i,j
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
            	int up = 0, left = 0;
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(i > 0)
                	up = dp[i-1][j];
                if(j > 0)
                	left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
int solveSpaceOptimized(int &m, int &n) {
	vector<int> prevDp(n,0);
	vector<int> temp(n,0);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			int up = 0, left = 0;
			if(i == 0 && j == 0){
				temp[0] = 1; 
				continue;
			}
			if(i > 0)
				up = prevDp[j];
			if(j > 0)
				left = temp[j - 1];

			temp[j] = up + left;
		}
		prevDp = temp;
	}
	return prevDp[n-1];
}
int uniquePaths(int m, int n) {
 	memset(memo,-1,sizeof(memo));
 	// return solveMemo(0,0,m,n);
 	// return solveTabulation(m,n);
 	return solveSpaceOptimized(m,n);
 }
int main() {
	init_code();
	cout << uniquePaths(3,7);
	return 0;
}
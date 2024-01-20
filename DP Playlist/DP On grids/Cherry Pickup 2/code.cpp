//In this question we have a fixd starting point and a variable ending point
//Generally in these type of questions we write the recursion from the starting
// point 

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 int solveMemo(int i1, int j1, int i2, int j2, int &m, int &n,vector<vector<int>>& grid) {
        //base cases
        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n) 
            return -1e8;

        if(i1 == m - 1){
            if(j1 == j2)
                return grid[i1][j1];
            else 
                return grid[i1][j1] + grid[i2][j2];
        }
        //For every direction of robot 1 we have three possible directions of robot 2
        int res = INT_MIN;
        for(int nj1 = -1; nj1 <= 1; nj1++){
            for(int nj2 = -1; nj2 <= 1; nj2++) {
                if(j1 == j2) 
                    res = max(res, grid[i1][j1] + solveMemo(i1 + 1, j1 + nj1, i2 + 1, j2 + nj2,m,n,grid));
                else 
                    res = max(res, grid[i1][j1] + grid[i2][j2] + solveMemo(i1 + 1, j1 + nj1, i2 + 1, j2 + nj2,m,n,grid));
            }
        }  
        return res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solveMemo(0,0,0,n-1,m,n,grid);
    }
int main() {
	init_code();
	vector<vector<int>> grid = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
	cout << cherryPickup(grid);
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 double knightProbability(int n, int k, int row, int column) {
        vector<vector<int>> jumps =  {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>> (n,vector<double> (n,0.0)));
        dp[0][row][column] = 1.0;
        for(int moves = 1; moves <= k; moves++) {
            for(int i = 0;  i < n ;i++){
                for(int j = 0; j < n; j++) {
                    for(auto dir: jumps) {
                        int prevI = i - dir[0];
                        int prevJ = j - dir[1];
                        if(prevI >= 0 && prevJ >= 0 && prevI < n && prevJ < n) 
                            dp[moves][i][j] += dp[moves-1][prevI][prevJ]/8;
                    }
                }
            }
        }
        double totalProb = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                totalProb += dp[k][i][j];
            }
        }
        return totalProb;
    }	
int main() {
	init_code();
	int n = 3, k=2, row = 0, column = 0;
	cout << knightProbability(n,k,row,column);
	return 0;
}

// Complexity Analysis
// Time complexity: O(k*n^2)

//  ).
// We have four nested for-loops: for moves, for i, for j, and for direction. The outer loop for moves runs kkk times, the second and third loops for i and for j iterate over all cells on the n×nn \times nn×n chessboard, and the innermost loop for direction iterates over the possible directions. As there are a constant number of directions (888), this loop can be considered as O(1)O(1)O(1) iterations.

// Within each state (moves,i,j)(\text{moves}, i, j)(moves,i,j), the time complexity is constant, as we perform simple calculations and update the dynamic programming table.

// The total number of iterations is determined by the product of the number of iterations in each loop: O(k⋅n2)O(k \cdot n^2)O(k⋅n 
// 2
//  ).

// Space complexity: O(k⋅n2)O(k \cdot n^2)O(k⋅n 
// 2
//  ).
// We use a three-dimensional dynamic programming table dp\text{dp}dp of size (k+1)×n×n(k+1) \times n \times n(k+1)×n×n to store the probabilities of being at each cell after a certain number of moves. Therefore, the space complexity is O(k⋅n2)O(k \cdot n^2)O(k⋅n 
// 2
//  ).
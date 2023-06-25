//this is an optimized approach for the n queen problem
// instead of traversing each time to check for the left lower and upper diagonal
//we can keep hasmaps for the each

//LEFT ROW
//for the left one we can simply have have a hash map tacking the row

//LOWER LEFT DIAGONAL
//for the lower left diagonat the sum of i+j will be same for each diagonal, hence we can keep a hashmap of size 2*n -1 tracking the same

//upper left diagonal
//for upper left diagon  we cna use the formula
//(n-1) + (col-row)
//we cant simply check for col-row as it might be ngative for some cells


#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 void solve(int col,int n, vector<string> board,vector<vector<string>> &ans,vector<int> leftRow,vector<int>upperDiagonal,vector<int>lowerDiagonal) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
       for(int row = 0; row < n; row++){
          if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col-row]==0) {
          	board[row][col] = 'Q';
          	leftRow[row] = 1;
          	lowerDiagonal[row+col] = 1;
          	upperDiagonal[n-1+ col-row] = 1;
          	solve(col+1,n,board,ans,leftRow,upperDiagonal,lowerDiagonal);
          	board[row][col] = '.';
          	leftRow[row] = 0;
          	lowerDiagonal[row+col] = 0;
          	upperDiagonal[n-1+ col-row] = 0;
          }
       }
    }
int main() {
	init_code();
	int n = 4;
	 vector<vector<string>> ans;
     vector<string> board(n);
     string temp(n,'.');
     for(int i = 0; i < n; i++) board[i] =temp;
     vector<int> leftRow(n,0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n -1, 0);
     solve(0,n,board,ans,leftRow,upperDiagonal,lowerDiagonal);

 	for(auto vec: ans) {
 		for(auto str: vec) {
 			cout << str << endl;
 		}
 		cout << "------------" << endl;
 	}
	return 0;
}

//Time complexty
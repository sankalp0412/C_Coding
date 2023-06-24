#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
bool isSafe(int row, int col, vector<string> board, int n ) {
        //check upper left diagonal
        int R = row;
        int C = col;
        while(row >= 0 && col >=0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        //check for left side
        row = R; col = C;
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        //check the left lower diagonal
         row = R; col = C;
        while(row < n && col >=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
      return true;  
    }
    void solve(int col,int n, vector<string> board,vector<vector<string>> &ans) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
       for(int row = 0; row < n; row++){
           if(isSafe(row,col,board,n)){
               board[row][col] = 'Q';
               solve(col+1,n,board,ans);
               board[row][col] = '.';
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
     solve(0,n,board,ans);

 	for(auto vec: ans) {
 		for(auto str: vec) {
 			cout << str << endl;
 		}
 		cout << "------------" << endl;
 	}
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class Solution {
public:
    bool rows[9][9];
    bool cols[9][9];
    bool grids[9][9];
    void setVal(int i, int j, int x, bool val) {
        rows[i][x] = val;
        cols[j][x] = val;
        int grid = (i/3) * 3 + (j/3);
        grids[grid][x] = val;
    }
    bool isValid(vector<vector<char>>& board, int i, int j, char c) {
        int grid = (i/3) * 3 + (j/3);
        int x = (c-'0') %9;
        if(!rows[i][x] && !cols[j][x] && !grids[grid][x])
            return true;
        return false;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) 
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.' ) {
                    for(char c = '1'; c<= '9'; c++) {
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;
                            int x = (c-'0') % 9;
                            setVal(i,j,x,1);
                            if(solve(board))
                                return true;
                            //backtrack
                            board[i][j] = '.';
                            setVal(i,j,x,0);
                        }
                    }
                return false;
                }
            }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) {
                if(board[i][j] != '.') {
                    int x = (board[i][j] - '0') % 9;
                    setVal(i,j,x,1);
                }
            }
        solve(board);
    }
};

int main() {
	init_code();
	vector<vector<char>> board ={
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
	Solution solution;
	solution.solveSudoku(board);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++) {
			cout <<board[i][j] << " ";
		}
		cout<<endl;
	}



	return 0;
}
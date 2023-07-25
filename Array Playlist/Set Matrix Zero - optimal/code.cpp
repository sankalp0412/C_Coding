//now instead of using an extra hash to trac
//which row and column should be 0
//we wll use the first row and column itself

// take care of edge cases as 
//we will use the first column totally
//but we will use an hypothetical first row
// we will start initializing zeros from the last
// and the first row and column in the last


#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

void setMatrixZero(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int col0 = 1;
	int m = matrix[0].size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 0) {
				//mark the i column
				matrix[i][0] = 0;
				if(j!=0)
					matrix[0][j] = 0;
				else 
					col0 = 0;
				//
			}	
		}
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(matrix[i][j] != 0) {
				//check for col & row
				if(matrix[0][j] == 0 || matrix[i][0] == 0){
					matrix[i][j] = 0;
				}
			}
		}
	}
	if(matrix[0][0] == 0){
		for(int j = 1; j < m; j++) matrix[0][j] = 0;
	}
	if(col0 == 0){
		for(int i = 0; i < n; i++) matrix[i][0] = 0;
	}
}

int main() {
	init_code();
	vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
	setMatrixZero(matrix);
	for(auto vec: matrix){
		for(auto x: vec) cout << x << " ";
		cout << endl;
	}
	return 0;
}
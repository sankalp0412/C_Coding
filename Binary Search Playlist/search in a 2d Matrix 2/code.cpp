#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int n = matrix.size();
	int m = matrix[0].size();

	int i = 0, j = m-1;
	while(i < n && j >= 0) {
		if(matrix[i][j] == target)
			return true;
		else if(matrix[i][j] < target) 
			i++;
		else 
			j--;
	}
	return false;        
}
int main() {
	init_code();
	vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
	int target = 14;
	cout << searchMatrix(matrix,target);
	return 0;
}
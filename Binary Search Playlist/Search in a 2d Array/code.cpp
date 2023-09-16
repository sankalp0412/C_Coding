#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

bool bs(vector<int> matrix, int &target) {
	int low = 0, high = matrix.size()-1;
	while(low <= high) {
		int mid = low + (high - low) /2;
		if(matrix[mid] == target)
			return true;
		else if(matrix[mid] < target)
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return false;
}
bool searchMatrix(vector<vector<int>> matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	for(int i = 0; i < m; i++) {
		if(matrix[i][0] <= target && matrix[i][n-1] >= target) {
			return bs(matrix[i],target);
		}
	}
	return false;
}
int searchMatrixOptimal(vector<vector<int>> matrix, int &target) {
	int n = matrix.size();
	int m = matrix[0].size();

	int low = 0, high = (n*m) - 1;

	while(low <= high) {
		int mid = (low + high) /2;
		int i,j;
	
		i = mid / n;
		j = mid % n;
		
		if(matrix[i][j] == target)
			return true;
		else if (matrix[i][j] < target) 
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return false;
} 
int main() {
	init_code();
	vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20},{23,30,34,60}};
	int target = 4;
	cout << searchMatrix(matrix,target) << endl;
	cout << searchMatrixOptimal(matrix,target);
	return 0;
}
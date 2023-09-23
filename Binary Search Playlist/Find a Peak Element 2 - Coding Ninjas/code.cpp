#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int maxIndex(vector<vector<int>> &matrix, int n, int m, int col) {
	int maxVal = -1;
	int index = -1;
	for(int i = 0; i <n ; i++) {
		if(matrix[i][col] > maxVal){
			maxVal = matrix[i][col];
			index = i;
		}
	}
	return index;
}
vector<int> findPeakGrid(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = m-1;
    while(low <= high) {
    	int mid = (low + high)/2;
    	int maxRowIndex = maxIndex(matrix,n,m,mid);
    	int left = mid - 1 >= 0 ? matrix[maxRowIndex][mid-1] : -1;
    	int right = mid + 1 < m ? matrix[maxRowIndex][mid + 1] : -1;
    	if(matrix[maxRowIndex][mid] > left && matrix[maxRowIndex][mid] > right) {
    		return {maxRowIndex,mid};
    	}
    	else if(matrix[maxRowIndex][mid] < left)
    		high = mid - 1;
    	else 
    		low = mid + 1;
    }
return {-1,-1};
}
int main() {
	init_code();
	vector<vector<int>> matrix = {{8,6}, {10,1}};
	vector<int> ans = findPeakGrid(matrix);
	cout << ans[0] << "," << ans[1];
	return 0;
}
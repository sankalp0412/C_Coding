#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		cnt += upper_bound(matrix[i].begin(),matrix[i].end(),x) - matrix[i].begin();
	}
	return cnt;
}
int median(vector<vector<int>> &matrix, int m, int n) {
   int low = INT_MAX, high = INT_MIN;
   n = matrix.size();
   m = matrix[0].size();
   for(int i = 0; i < n; i++) {
   	low = min(low,matrix[i][0]);
   	high = max(high,matrix[i][m-1]);
   }

   int req = (n*m)/2;

   while(low <= high) {
   	int mid = (low + high)/2;
   	int smallEqual = countSmallEqual(matrix,n,m,mid);
   	if(smallEqual<= req) 
   		low = mid +1;
   	else 
   		high = mid - 1;
 }
 return low;
}	
int main() {
	init_code();
	vector<vector<int>> matrix = {{1,5,8,9,11}, {2,3,4,8,9}, {4,11,14,19,20},{6,10,22,99,100} ,{7,15,17,24,28}};
	cout << median(matrix,matrix.size(),matrix[0].size());
	return 0;
}
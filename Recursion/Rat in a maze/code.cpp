//Time Complexit: 4 power n*m roughlt
//as for every cell i am checking 4 directions.
//space will be max depth of recursoin ie: O(m*n)



#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
bool isValid(int i, int j,int n, vector<vector<int>> matrix, vector<vector<int>> vis) {
	if(i >= 0 && j >= 0 && i < n && j < n && matrix[i][j] == 1 && !vis[i][j])
		return true;
	return false;
} 
void solve(int i, int j, string path, vector<vector<int>> &matrix,vector<vector<int>> vis, int n, vector<string> &ans) {
	//base case
	if(i == n-1 && j == n-1) {
		ans.push_back(path);
		return;
	}
	vis[i][j] = 1;
	vector<vector<int>> dxy = {{0,-1}, {-1,0}, {0,1}, {1,0}};
	vector<char> dir = {'L','U','R','D'};
	for(int k = 0; k < 4; k++) {
		int x = i + dxy[k][0];
		int y = j + dxy[k][1];
		if(isValid(x,y,n,matrix,vis)) {
			path += dir[k];
			solve(x,y,path,matrix,vis,n,ans);
			//backtrack
			path.pop_back();
		}
		//backtrack
	}
	vis[i][j] = 0;
	return;
}
vector<string> findPath(vector<vector<int>> matrix, int n) {
	vector<string> ans;
	vector<vector<int>> vis(n,vector<int> (n,0));
	if(!matrix[0][0] || !matrix[n-1][n-1]) return ans;
    solve(0,0,"",matrix,vis,n,ans);
    return ans;
}
int main() {
	init_code();
	vector<vector<int>> matrix = {{1,0,0,0},{1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
	int n = matrix.size();
	// cout << n;
	auto ans = findPath(matrix,n);
	for(auto str: ans){
		for(auto it: str){
			cout << it;
		}
		cout<<endl;
	}
	return 0;
}
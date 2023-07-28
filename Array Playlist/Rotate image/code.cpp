#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n-1; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i <n; i++){
        	reverse(matrix[i].begin(),matrix[i].end());
        }
    }

int main() {
	init_code();
	vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}};
	rotate(vec);
	for(auto v: vec){
		for(auto x: v) cout << x << " ";  
		cout << endl;
	}
	return 0;
}
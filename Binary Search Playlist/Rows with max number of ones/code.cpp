#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
    int lowerBound(vector<int> &arr, int target) {
        int n = arr.size();
        int low = 0, high =n-1;
        int ans = n;
        while(low <= high) {
            int mid = (low + high)/2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid -1;
            }
            else 
                low = mid + 1;
        } 
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_cnt = INT_MIN;
        vector<int> ans;
        for(int i = 0; i < mat.size(); i++) {
            sort(mat[i].begin(),mat[i].end());
            int index = lower_bound(mat[i].begin(),mat[i].end(),1) - mat[i].begin();
            int cnt = mat[i].size() - index;
            if(cnt > max_cnt){
                ans = {i,cnt};
                max_cnt = cnt;
            }
        }
        return ans;
    }
int main() {
	init_code();
	vector<vector<int>> vec = {{0,1},{1,0}};
	auto ans =  rowAndMaximumOnes(vec);
	cout << ans[0] << "," << ans[1];
	return 0;
}
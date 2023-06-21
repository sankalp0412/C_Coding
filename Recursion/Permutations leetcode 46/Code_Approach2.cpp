//this approah will be saving space as we are not using any extra data structure
//intuitiion: every number should be at a particular index

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
void solve(vector<vector<int>> &ans,int index, vector<int> nums) {
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            swap(nums[index],nums[i]);
            solve(ans,index+1,nums);
            swap(nums[index],nums[i]);
        }

    }
int main() {
	init_code();
	vector<int> nums = {1,2,3};
	 vector<vector<int>> ans;
     int n = nums.size();
     solve(ans,0,nums);
	return 0;
}
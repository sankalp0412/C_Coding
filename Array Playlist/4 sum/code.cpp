#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

vector<vector<int>> fourSum(vector<int> &nums, int &target) {
	int n = nums.size();
	sort(nums.begin(),nums.end());
	vector<vector<int>> ans;
	for(int i = 0; i < n; i++) {
		if(i > 0 && nums[i] == nums[i-1]) continue;
		for(int j = i + 1; j < n; j++) {
			if(j != i + 1 && nums[j] == nums[j-1]) continue;
			int k = j + 1;
			int l = n - 1;
			while(k < l) {
				long long sum = nums[i];
				sum += nums[j];
				sum += nums[k];
				sum += nums[l];
				if(sum == target) {
						vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
						ans.push_back(temp);
						k++;l--;
						while(k < l && nums[k] == nums[k-1])k++;
						while(k < l && nums[l] == nums[l+1])l--;
				}
				else if(sum > target) l--;
				else k++;				
			}
		}
	}
	return ans;
}
int main() {
	init_code();
	vector<int> nums = {1,0,-1,0,-2,2};
	int target = 0;
	vector<vector<int>> ans = fourSum(nums, target);
	for(auto vec: ans){
		for(auto x: vec) cout << x << ",";
		cout << endl;
	}
	return 0;
}

//TC: ~~O(n^3)
//SC: O(number of quads) for returning ;
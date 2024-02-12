#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
vector<vector<int>> better(vector<int> nums) {
	set<vector<int>> hashSet;
	int n = nums.size();
	for(int i = 0; i < n; i++) {
		set<int> hash;
		for(int j = i+1; j < n; j++) {
			int thirdEle = -(nums[i] + nums[j]);
			if(hash.find(thirdEle) != hash.end()) {
				vector<int> temp = {nums[i],nums[j], thirdEle};
				sort(temp.begin(),temp.end());
				hashSet.insert(temp);
			}
			hash.insert(nums[j]);
		}
	}
	vector<vector<int>> ans(hashSet.begin(),hashSet.end());
	return ans;
}

vector<vector<int>> optimal(vector<int> nums) {
	int n = nums.size();
	sort(nums.begin(),nums.end());
	vector<vector<int>> ans;
	for(int i = 0; i < n; i++) {
		if(i > 0 && nums[i] == nums[i-1]) continue;
		int j = i + 1;
		int k = n -1;
		while(j < k) {
			int sum = nums[i] + nums[j] + nums[k];
			if(sum < 0) {
				j++;
			}
			else if(sum > 0){
				k--;
			}
			else {
				vector<int> temp = {nums[i],nums[j],nums[k]};
				ans.push_back(temp);
				j++;
				k--;
				while(j < k && nums[j] == nums[j-1]) j++;
				while(j < k && nums[k] == nums[k+1]) k--;
			}
		}
	}
	return ans;
}
int main() {
	init_code();
	vector<int> nums = {-1,0,1,2,-1,-4};
	vector<vector<int>> ans = optimal(nums);
	for(auto vec: ans) {
		for(auto x: vec) cout << x << " ";
		cout << endl;
	}
	return 0;
}

//tc : nlogn to sort
// O(n) for loop
// the while loop will run for n-1 first then n-2 then n-3
//ans so on so near about n^2;\
//TC: O(nlogn) + (n^2);
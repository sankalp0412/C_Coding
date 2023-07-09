//this approach is only good for positives
//wont work if we have 0 in array
//eg if array is 2,0,0,3
//here with our code we will get 1 as max leng
//but it should be 0,0,3 ie 3 --------- so ths will be optimal if array has negatives as well
//hence we will add the check on line 28

#include "bits/stdc++.h"
using namespace std;
#define for(i,n) for(int i = 0; i < n; i++)

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int longestSubarray(vector<int> nums, int target) {
	int sum = 0, ans = INT_MIN;
	unordered_map<int,int> mp;
	int n = nums.size();
	for(i,n){
		sum += nums[i];
		if(mp.count(sum - target)){
			ans = max(ans,i - mp[sum-target]);
		}	
		if(!mp.count(sum))
			mp[sum] = i;
	}
	return ans;
}
int main() {
	init_code();
	vector<int> nums = {2,0,0,3};
	int target = 3;
	cout << longestSubarray(nums,target);
	return 0;
}


//Time Complexity
//O(nlogn) is we are using ordered map
// O(n*1) for unordered map can be n^2 in worst case


//SC (We are storing prefix sum)
//O(n) as in worst case every index will have 
//its own unique prefix sum 
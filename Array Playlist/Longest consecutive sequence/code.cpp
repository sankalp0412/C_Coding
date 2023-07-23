//OPTIMAL SOLUTION
//TC: o(N) WORST CASE for set in case of collison
// the second while loop is not an N iteration
//as we are not staring from everyone but only from the firs guy
//O(3n) = O(n)

//SC: O(n)

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int solve(vector<int> nums) {
	int n = nums.size();
	set<int> st;
	if(!n) return 0;
	int longest = 1;
	for(auto it: nums)
		st.insert(it);

	for(auto it: st) {
		if(st.find(it-1) == st.end()) {
			int cnt = 1;
			int x = it;
			while(st.find(x+1) != st.end()){
				x += 1;
				cnt = cnt+1;
			}
			longest = max(longest, cnt);
		}
	}
	return longest;
}
int main() {
	init_code();
	vector<int> nums = {100,4,200,1,2,3};
	cout << solve(nums);
	return 0;
}
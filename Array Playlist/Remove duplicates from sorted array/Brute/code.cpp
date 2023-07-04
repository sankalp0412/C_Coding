#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int solve(vector<int> &nums) {
	set<int> s;
	int index = 0;
	for(auto x: nums)
			s.insert(x);
	for(auto it: s) 
			nums[index++] = it;
}
int main() {
	init_code();
	vector<int> nums = {1,2,2,3,3,4,5};
	return 0;
}

//time complexi:
// insertion in set takes NlogN and inserting back into nums o(n);
// so nlogn + n;

//Space Complexity:
//O(n) of the set, as in worst case when there are no duplicates set 
//will take n space.
//Mooores voting algo/

//intution is that if any element is appering more than n/2 times 
// it cannot get cancelled 
// as we will required another n - n/2 which is not possible 

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

int majorityElement(vector<int> nums) {
	int n = nums.size();
	int cnt = 0, el;
	for(int i = 0; i < n; i++) {
		if(cnt == 0) {
			cnt = 1;
			el = nums[i];
		}
		else if(nums[i] == el)
			cnt++;
		else 
			cnt--;
	}
	cnt = 0;
	for(int i = 0; i < n; i++){
		if(nums[i] == el)
			cnt++;
	}
	if(cnt > n /2)
		return el;
	return -1;

}

int main() {
	init_code();
	vector<int> nums = {2,2,1,1,1,2,2};
	cout << majorityElement(nums);
	return 0;
}


//TC: O(n) for the first loop
// the second loop only required if 
// the problem states that there might 
// not be a maority element
// in that case we will have to veriy

//SC: O(1)

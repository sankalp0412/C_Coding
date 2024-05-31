#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
vector<int> singleNumber(vector<int>& nums) {
 if(nums.size() == 2) return nums;
	int totXor = 0;
	int val1 = 0, val2 = 0;
	for(int i = 0; i < nums.size(); i++) totXor ^= nums[i];

	for(int i = 0; i < 32; i++) {
		//we will find the bit that was not same in the two values
		if((totXor >> i) & 1) {
			//val1 will be the value with 0 at the ith but, and val2 will the unmber with 1 at the ith bit
			for(int j = 0; j < nums.size(); j++) {
				if((nums[j] >> i) & 1)
					val2 ^= nums[j];
				else 
					val1 ^= nums[j];
			}
            break;
		} 
	}

	return {val1,val2};

}
int main() {
	init_code();
	vector<int> nums = {1,2,1,3,5,2};
	auto ans =  singleNumber(nums);
	cout << ans[0] << "," << ans[1];
	return 0;
}



// One important point is that by XORing all the numbers, 
// we actually get the XOR of the two target numbers 
// (because XORing two duplicate numbers always results 
// in 0). Consider the XOR result of the two target
//  numbers; if some bit of the XOR result is 1, it
//   means that the two target numbers differ at that 
//   location.

// Let’s say the at the ith bit, the two desired 
// numbers differ from each other. which means one 
// number has bit i equaling: 0, the other number has 
// bit i equaling 1.

// Thus, all the numbers can be partitioned into two 
// groups according to their bits at location i.
// the first group consists of all numbers whose 
// bits at i is 0.the second group consists of all 
// numbers whose bits at i is 1.

// Notice that, if a duplicate number has bit i as 0,
//  then, two copies of it will belong to the first 
//  group. Similarly, if a duplicate number has bit 
//  i as 1, then, two copies of it will belong to the 
//  second group.

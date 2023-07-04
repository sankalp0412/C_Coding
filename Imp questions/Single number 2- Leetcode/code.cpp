//4 4 4  3 3 3 1 2 2 2
//if we write these in binary
//100
//100
//100
//011
//011
//011
//001
//010
//010
//010

//if i consider the 0th bit and count all the 1's
//i see we have 4 set bits
//now out of these 3 will definitely belon to a group of 3
//so the number we are trying to find has '1' in the 0th bit





#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int singleNumber(vector<int> &vec) {
	int ans = 0;
	for(int i = 0; i < 32; i++) {
		int countSetBits = 0;
		for(int j = 0; j < vec.size(); j++) {
			if((vec[j] >> i) & 1) {
				countSetBits++;
			}
		}
		if(countSetBits % 3) {
			ans |= 1 << i;
		}
	}
	return ans;	
}
int main() {
	init_code();
	vector<int> vec = {4,4,4,1,3,3,3,2,2,2};
	cout << singleNumber(vec);
	return 0;
}
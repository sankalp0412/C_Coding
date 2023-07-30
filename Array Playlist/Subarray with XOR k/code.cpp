#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int subarraysXor(vector<int> &arr, int x) {
   unordered_map<int,int> frontXor;
   frontXor[0] = 1;
   int n = arr.size(), currXor = 0, ans = 0;
   for(int i = 0; i < n; i++) {
       currXor = currXor ^ arr[i];
       int reqXor = currXor ^ x;
       if(frontXor.find(reqXor) != frontXor.end()){
           ans += frontXor[reqXor];
       }
       frontXor[currXor]++;  
   }
   return ans;
}

int main() {
	init_code();
	vector<int> nums = {5,3, 8, 3, 10};
	cout << subarraysXor(nums,8);
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int myContestSolution(vector<int> &nums) {
	int n = nums.size();
   	   if(n == 1) return !nums[0];
   	   int ans = 0;
   	   
   	   //lets position j at the last 1
   	   int i,j = n - 1;
   	   
   	   while(j >= 0 && nums[j] != 1)
   	       j--;
   	   
   	   //if there are trailing zeroes
   	   if(j != n-1) ans += 1;
   	   i = j-1;
   	   
   	   while(i >= 0) {
   	      if(nums[i] == 0 && nums[j] == 1){
   	          while(i >= 0 && nums[i] == 0)
   	              i--;
   	          ans += 2;
   	          j = i;
   	          i = j - 1;
   	      }
   	       else {
   	           i--;
   	           j--;
   	       }
   	   }
   	  	
   	   return ans;
}
int minOperations(vector<int>& nums) {
    int flips = 0;
    for(auto &x: nums) {
        if(flips % 2){
            //odd number of flips 
            flips += x;
        }
        else {
            //even number of times
            //means if x == 1 it will remain 1 if x == 0 it will remain 0
            flips += !x;
        }
    }
    return flips;
}
//better way to write the above solution
int bestSolution(vector<int> &nums) {
	int ans = 0;
        for(auto &x: nums) {
            if(x ==  ans % 2)
                ans += 1;
        }
    return ans;
}
int main() {
	init_code();
	vector<int> nums = {0,1,1,0,1};
	cout << minOperations(nums);

	return 0;
}
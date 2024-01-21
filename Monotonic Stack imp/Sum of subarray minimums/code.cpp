// https://www.youtube.com/watch?v=aX1F2-DrBkQ
//Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

//The numebr of subarray for an array of size n is n^2
//The idea is to find out how many times each number is going to be the minimum
// of a subarray i.e. how many times each number is going to be contributed.

//The main part is to figure out in how many subarrays an element will be minimum.

//for Each element will we find out the number of subarrays to its right and left
// where it will be minimum and the multiply. (multiply as we can make combinations from both right and left)
// 
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int sumSubarrayMins(vector<int>& arr) {
      const int MOD = 1000000007;
        stack<int> st;
        long sumOfMinimums = 0;

        for (int i = 0; i <= arr.size(); i++) {
            while (!st.empty() && (i == arr.size() || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                int leftBoundary = st.empty() ? -1 : st.top();
                int rightBoundary = i;

                long count = (mid - leftBoundary) * (rightBoundary - mid) % MOD;

                sumOfMinimums += (count * arr[mid]) % MOD;
                sumOfMinimums %= MOD;
            }
            st.push(i);
        }

        return static_cast<int>(sumOfMinimums);  
}
int main() {
	init_code();
	vector<int> arr = {3,1,2,4};
	cout << sumSubarrayMins(arr);
	return 0;
}
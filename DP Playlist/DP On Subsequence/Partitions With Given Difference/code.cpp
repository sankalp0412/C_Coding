#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

//Total - d >= 0
//and 
//total - D should be even 

int mod = 1e9 + 7;
int countSubsetWithSumK(vector<int> &arr, int k, int &n) {
	vector<int> prev(k + 1,0), curr(k + 1,0);
	prev[0] = 1;
	curr[0] = 1;
	if(arr[0] <= k) prev[arr[0]] = 1;
	if(arr[0] == 0) curr[0] = prev[0] = 2; 

	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= k; j++) {
			int notTake = prev[j];
			int take = 0;

			if(j >= arr[i])
				take = prev[j - arr[i]];

			curr[j] = (take + notTake) % mod;
		}
		prev = curr;
	}

	return prev[k];
}
int countPartitions(int n, int d, vector<int> &arr) {
	int total = accumulate(arr.begin(),arr.end(),0);
	int sum = (total - d)/2; //and now this is same as count number of subsets with sum k
	if((total - d) <= 0 || (total - d) % 2)  return 0;

	return countSubsetWithSumK(arr,sum, n);
}

int main() {
	init_code();
	int n =4, d = 0;
	vector<int> arr = {1, 1, 1, 1};
	cout << countPartitions(n,d,arr);
	return 0;
}
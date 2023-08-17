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
int solve(vector<int> &arr) {
	int n = arr.size();
        if(n==1) return 0;
        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2]) return n-1;

        int low = 1, high = n - 1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            }
            else if(arr[mid] > arr[mid-1]) low = mid +1;
            else high = mid - 1;
        }
        //dummy return code, will never come here
       return -1; 
}
int main() {
	init_code();
	vector<int> arr = {1,2,1,3,5,6,4};
	cout << solve(arr);
	return 0;
}
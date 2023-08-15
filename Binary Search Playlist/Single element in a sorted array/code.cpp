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

int singleNonDuplicate(vector<int>& arr) {
	  int n = arr.size();
        if(n == 1) return arr[0];
        int low = 0, high = n-1, mid;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(mid == 0 || mid == n-1) return arr[mid];
            if(arr[mid-1] == arr[mid]) {
                //len of the right array
                int len = (high - (mid + 1)) + 1;
                if(len & 1) //len is odd, element on the right side
                    low = mid + 1;
                else 
                    high = mid - 2;
            }
            else if(arr[mid+1] == arr[mid]){
                //len of the left subarray
                int len = ((mid-1) - low) + 1;
                if(len & 1)
                    high = mid -1;
                else 
                    low = mid + 2;
            }
            else return arr[mid];
        }
        return arr[mid];      
}

int main() {
	init_code();
	vector<int> nums = {1,1,2,3,3,4,4,8,8};
	cout << singleNonDuplicate(nums);
	return 0;
}
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
int findMin(vector<int>& arr) {
        int ans = INT_MAX;
        int low = 0, high = arr.size()-1, mid;
        while(low<= high) {
            mid = (low+high)/2;
            //if search space is already sorted
            //arr of low will always be lower than any other element
            if(arr[low] <= arr[high]) {
                ans = min(ans,arr[low]);
                break;
            }
            if(arr[mid] < arr[high]){ // right part is sorted
                ans = min(ans,arr[mid]);
                high = mid -1;
            }
            else {//left part is sorted
                ans = min(arr[low], ans);
                low = mid + 1;
            }
        }
        return ans;
    }
int main() {
	init_code();
	vector<int> arr = {3,4,5,1,2};
	cout << findMin(arr);
	return 0;
}

//step 1:
//find the part of arra which is sorted
//by comparing mid value to the high or low
//so the sorted part might contain my lowest value
// we can eliminate is by directly pickig up the minimum value
// by using and comparing low or mid like in line 19 and 20;
// here if the right part is sorted than i only need to compare with the
// lowest value in the right half that is mid
// similarliy for the left half will will compare with low/


//optimization :::

// if for an array both the left half and the right half are sorted:
// eg: [4,5,6 ,0,1,2]


//first we compare mid with left half and ans = 4;
// now we are left with [0,1,2]

//here both the left half and the right half are sorted:
//i.e arr[low] <= mid && arr[mid] <= arr[high]

//which togerther we can right as arr[low] <= arr[high]

//this only happens when we cross the point of rotation, on either side.

//so we can use the above condition to break
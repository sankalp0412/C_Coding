#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
  bool possible(vector<int> weights, int capacity, int days) {
        int numOfDays = 0;
        int wt = 0;
        for(auto w: weights) {
            if(wt + w <= capacity)
                wt += w;
            else {
                numOfDays++;
                wt = w ;
            }
        }
        numOfDays += (int)(wt <= capacity);
        return numOfDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low <= high) {
            int mid = (low + high)/ 2;
            if(possible(weights,mid,days))
                high = mid -1;
            else 
                low = mid + 1;
        }
        return low;
    }
int main() {
	init_code();
	vector<int>weights = {1,2,3,4,5,6,7,8,9,10};
	int days = 5;
	cout << shipWithinDays(weights,days);
	return 0;
}
//here also we are applying BS on the answers 
// the max value of the answer can be the total weight
//i.e 55 in above case: if i have a ship with capactiy 55
// i can load everthing in a single day
// and the min value will be the max weight that i need to 
// ship, as if the capacity is 8 i can't ship the weight 9 and 
//10
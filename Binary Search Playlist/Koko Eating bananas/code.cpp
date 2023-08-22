#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
double solve(vector<int> &piles, int rate) {
        double ans = 0;
        for(int i = 0; i < piles.size(); i++) {
            ans += (piles[i] + (rate - 1)) / rate;
        }
        return ceil(ans);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxRate = *max_element(piles.begin(),piles.end());
        int low = 1, high = maxRate;
        int mid;
        while(low <= high) {
            mid = low + (high - low)/2;
            auto reqTime = solve(piles,mid);
            if(reqTime > h) 
                low = mid + 1;
            else {
                high = mid -1;
            }
        }
        return low;
    }
int main() {
	init_code();
	vector<int> piles =  {30,11,23,4,20};
	int h = 6;
	cout << minEatingSpeed(piles,h);
	return 0;
}

//EG: [3,6,7,11]
//highest possible = 11\

//at the end the scenario will be 
//[1,2,  3 ,  4,  5 , 6 , 7 ,8,9,10,11]
//     high  low

//in binary search at the end, high and low will have opposite 
// polarity that means if low was initially not possible then
//in the end it will be at possible.
//hence at the end we will just reutnr low
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

class Solution {
public:
    bool possible(int separation, vector<int> &position, int m) {
        int prevBall = position[0]; 
        //we will always start by placing first ball at the first position
        int cnt = 1;

        for(int i =1; i < position.size(); i++) {
            int curr = position[i];
            if(curr - prevBall >= separation){
                //means we can place a ball at curr
                cnt += 1;
                prevBall = curr;
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());

        int low = 1;
        int high = ceil(position[n-1]/(m - 1));

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(possible(mid,position,m))
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return high;
    }
};
int main() {
	init_code();
	vector<int> position = {5,4,3,2,1,1000000000};
	int m = 2;
	Solution sol;
	cout << sol.maxDistance(position,m);
	return 0;
}


// Why the gap is capped at 
// maxPosition / m - 1

// The maximum gap (high) considers the scenario where 
// the positions are distributed as evenly as possible.
// If you have m balls, you can think of placing m-1 
// gaps between them.
// The widest possible gap occurs if you distribute 
// these m-1 gaps as evenly as possible over the entire
// range from the first position to the last position 
// (i.e., position[n-1]).
// To understand this, consider distributing m balls 
// into n positions: The most spread-out configuration 
// will have the largest minimum gap between adjacent 
// balls.
// The maximum possible spread will be achieved when
 // each gap is roughly equal to 
// maxPosition / m - 1
//https://www.youtube.com/watch?v=zx5Sw9130L0 - Neetcode
//As per discussion this question is a pre-req for the daily challege
//question 'Largest Submatrix With Rearrangements' on leetcode.

//  2
//1 2

//in the above scenario we can still keep extending the height of 2 
// towards the right, as there is no smaller height that comes after it.

// 2  _____>
      // _______>
// 2 1

//but in this case we can't keep extending towards the right although we can
 // extend towards the left. (using the 'lastPoppedIndex' variable in the code)
// hence when we go at index 1, and pop the 2 at index 0. We are going to make
//the index of 1 as 0, as since we can extend it toward back side. (See screenshot 2)


//			4
//		3	4
//	2	3	4
//  2	3	4	 2
//1 2	3  |4|   2 

// here i can't extend the 4 any more, so the boudaries of 4 are till the 
//building with two is started.
// we can't extend 3 any further as well so pop it as well after calcluate area.
 // we don't have to pop two as sine equal so we can still extend it further.

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
 int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int,int>> s;
        for(int i = 0; i < n ; i++) {
            int curr = heights[i];
            if(s.empty() || curr >= s.top().second)
                s.push({i,curr});
            else {
                int lastPoppedIndex;
                while (s.size () && curr < s.top().second) {
                    int len = i - s.top().first;
                    int h = s.top().second;
                    maxArea = max(maxArea, len *h);
                    lastPoppedIndex = s.top().first;
                    s.pop();
                }
                s.push({lastPoppedIndex,curr});
            }
        }
        while(!s.empty()) {
            int idx = s.top().first;
            int h = s.top().second;
            maxArea = max(maxArea, h * (n - idx));
            s.pop();
        }
        return maxArea;
    }
int main() {
	init_code();
	vector<int> heights = {2,1,5,6,2,3};
	cout << largestRectangleArea(heights); 
	return 0;
}

// REFER SCREENSHOT 3
//when we reach at index 4 (height 2), we see that the prev height
// 6 is greater so we can't extend 6 any further
// so before popping we will try to find the area
// height = 6 at index 3;
// and ends at index 4 
// so 6 * (4-3) = 6
//
// now we pop 6 and check ofor 5, even 5 is greater that 2
// so now we find the area 
// height = 5 at index 2
//and ends (extends at) 4
// so 5 * (4 - 2) = 10


// now we have 2 (actually at index 1, but since we changed it index by extending
// it towards left its index is 0, see point at line 16)
// so we don't pop it 


//also we poopped 6 and 5 so basically 2 (at index 4) can be extended towards
// left all the way at index 2 (REFER SCREENSHOT 4)


// at the end we will still have 3 elements left in the stack that we were able
// to EXTENDED ALL THE WAY i.e. to the last index.
// so will still need to calculate the area we could have made from that

//refer screenshot 5

//for the bar with height 3 index (last index (n));
// we took it to the end i.e. till index 5
// so area = 3 * (n - 5) = 3

//for the bar iwth the height 2 (acutal index 4, but new index 2)
//area = 2 * (n - 2)
// area = 8

//for the bar iwth height 1 (index 0, actual index 1)
// area = 1 * (n - 0) = 6

//neither is greater than 10 
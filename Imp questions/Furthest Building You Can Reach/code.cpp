//WE will maintain the jump we took using bricks 
//in a pq (max Heap)

//So in future if we encounter a jump that is less than
//the highest jump we have taken so far with the bricks
//so we will replace it with ladder as 
//ideally for optimal solution we should take the highest
//jumps with ladder

//for example if we took a jump of 8 with brickes
//in future we encounter a jump of 6,
//so ideally we should have taken the earlier 8 one with
// ladder
//so we will switch	

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
	int n = heights.size();
	int i; 
	priority_queue<int> pq;
	for(i = 0; i + 1 < n; i++) {
		int jump = heights[i+1] - heights[i];
		if(jump <= 0) continue;

		//can we take this jump with the bricks
		if(jump <= bricks) {
			bricks -= jump;
			pq.push(jump);
		}
		//else check if we can take the jump with the ladder
		else if(ladders > 0) {
			//check if the current jump if less than
			//the max jump we have taken in the past with the bricks
			if(pq.size() && jump < pq.top()) {
				//this means we should have taken the earlier one with ladder
				bricks += pq.top();
				pq.pop();
				//take the curr jump with bricks
				bricks -= jump;
				pq.push(jump);
			}
			ladders--; 
		}
		else break;
	}
	return i;
}
int main() {
	init_code();
	vector<int> heights = {4,12,2,7,3,18,20,3,19};
	int bricks = 10, ladders = 2;
	cout << furthestBuilding(heights,bricks,ladders);
	return 0;
}
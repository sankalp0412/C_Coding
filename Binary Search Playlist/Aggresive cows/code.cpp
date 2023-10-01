// this question is similar to leet code 1552, magnetic force between balls

#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
bool possible(vector<int> &stalls, int dis, int k) {
    int cntCows = 1;
    int last = stalls[0];
    for(int i = 1; i < stalls.size(); i++) {
        if(stalls[i] - last >= dis){
            last = stalls[i];
            cntCows++;
        }
    }
    return cntCows >= k;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int low = 1, high = stalls[n-1] - stalls[0];
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(possible(stalls,mid,k))
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return high;
}
int main() {
	init_code();
	vector<int> stalls = {0, 3 ,4 ,7 ,10,9};
	int k = 4;
	cout << aggressiveCows(stalls,k);
	return 0;
}
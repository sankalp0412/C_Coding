#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
struct Job {
    int st;
    int et;
    int profit;
    Job(int start, int end, int pro){
        this -> st = start;
        this -> et = end;
        this -> profit = pro;
    }
};
class Solution {
public:
    int bs(vector<Job> &jobs, int &endTime, int &idx) {
        int low = idx + 1, high = jobs.size() - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int st = jobs[mid].st;
            if(st >= endTime) 
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return low;
    }
    int solveMemo(int idx, vector<Job> &jobs,vector<int> &memo) {
        if(idx >= jobs.size())
            return 0;
        
        if(memo[idx] != -1)
            return memo[idx];
        int take = 0, notTake = 0;
        //To find the minimum index of next possible job
        int nextPossibleJob = bs(jobs,jobs[idx].et, idx);

        take = jobs[idx].profit + solveMemo(nextPossibleJob, jobs,memo);
        notTake = solveMemo(idx + 1, jobs,memo);

        return memo[idx] = max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        int n = profit.size();
        for(int i = 0; i < n; i++) 
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        sort(jobs.begin(),jobs.end(),[&](auto &j1, auto &j2) {
            return j1.st < j2.st;
        });
        
        vector<int> memo(n,-1);
        // return solveMemo(0,jobs,memo);
        return solveTabulation(startTime,endTime,profit);
    }
    int solveTabulation(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    	vector<Job> jobs;
        int n = profit.size();
        for(int i = 0; i < n; i++) 
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        sort(jobs.begin(),jobs.end(),[&](auto &j1, auto &j2) {
            return j1.st < j2.st;
        });
        
        vector<int> dp(n, 0);
        dp[n-1] = jobs[n-1].profit; //as if there is only one job i.e the last job then the profit will be the profit of the last job
        for(int i = n-2; i >= 0; i--) {
            int nextJob = bs(jobs,jobs[i].et,i);

            //if the lb is available then we will add the profit of the lb index 
            int take = jobs[i].profit + (nextJob == n ? 0: dp[nextJob]);

            //if we are not taking then we will just fetch the profit of the very next job
            int notTake = dp[i+1];

            dp[i] = max(take,notTake); 
        }
        return dp[0];
    }
};
int main() {
	init_code();
	vector<int> startTime = {1,2,3,3}, endTime = {3,4,5,6}, profit = {50,10,40,70};
	Solution sol;
	cout << sol.jobScheduling(startTime,endTime,profit);
	return 0;
}


//once we have sorted wrt start time
// for every job we need to find the minimum job whose
// start time >= endTime of the previous job (for this we will bs)

//
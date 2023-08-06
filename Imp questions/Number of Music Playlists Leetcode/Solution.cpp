#include "bits/stdc++.h"
#include "Solution.h"

    long long Solution::solve(int currGoal, int distOldSongs, int &n, int &k) {
        //base cases
        if(currGoal == 0 && distOldSongs == n)
            return 1;
        if(currGoal == 0 or distOldSongs > n)
            return 0;

        if(dp[distOldSongs][currGoal] != -1) return dp[distOldSongs][currGoal];
        long long cnt = 0;
        //Choices
        //Choose a new song 
        cnt +=  ((n - distOldSongs) * (solve(currGoal - 1, distOldSongs + 1,n,k)) % mod) % mod;

        //Choose an old song
        if(distOldSongs > k)
            cnt += ((distOldSongs- k) * (solve(currGoal - 1, distOldSongs,n,k)) %mod ) % mod;
        
        cnt %= mod;

        return dp[distOldSongs][currGoal] = int(cnt);
        }
    int Solution::numMusicPlaylistsMemo(int n, int goal, int k) {
        dp.resize(n+1,vector<long long>(goal+1,-1));
        return solve(goal,0,n,k);
    }
// Solution.h
#ifndef SOLUTION_H
#define SOLUTION_H
#include "bits/stdc++.h"

class Solution {
public:
    long long mod = 1e9 + 7;
    std::vector<std::vector<long long>> dp;

    long long solve(int currGoal, int distOldSongs, int &n, int &k);

    int numMusicPlaylistsMemo(int n, int goal, int k);
};


#endif
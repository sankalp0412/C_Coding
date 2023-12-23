#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
//to compute a day we only need the data of the very previous day
//so we can optimize the space.
int solveSpaceOptimization(int n, vector<vector<int>> &points){
	vector<int> prev(4);
   prev[0] = max(points[0][1],points[0][2]);
   prev[1] = max(points[0][0],points[0][2]);
   prev[2] = max(points[0][1],points[0][0]);
   prev[3] = max(points[0][1],max(points[0][0],points[0][2]));
   for(int day = 1; day < n; day++) {
       vector<int> temp(4);
       for(int last = 0; last < 4; last++) {
           temp[last] = 0;
           for(int act = 0; act < 3; act++) {
               if(act != last){
                int point = points[day][act] + prev[act];
                temp[last] = max(temp[last],point);
               }
           }
       }
        prev = temp;
   }
   return prev[3];
}
int solveTabulation(int n, vector<vector<int>> &points){
	vector<vector<int>> dp(n,vector<int> (4,-1));
   dp[0][0] = max(points[0][1],points[0][2]);
   dp[0][1] = max(points[0][0],points[0][2]);
   dp[0][2] = max(points[0][1],points[0][0]);
   dp[0][3] = max(points[0][1],max(points[0][0],points[0][2]));
   for(int day = 1; day < n; day++) {
       for(int last = 0; last < 4; last++) {
           dp[day][last] = 0;
           for(int act = 0; act < 3; act++) {
               if(act != last){
                int point = points[day][act] + dp[day-1][act];
                dp[day][last] = max(dp[day][last],point);
               }
           }
       }
   }
   return dp[n-1][3];
}
int solveMemo(int day,int &n, vector<vector<int>> &points, int prev,vector<vector<int>> &memo) {
    if(day == n - 1){ //last day
    int maxPts = 0;
        for(int i = 0; i < 3; i++){
            if(prev != i)
                maxPts = max(maxPts, points[day][i]);
        }
        return maxPts;
    }
    if(memo[day][prev] != -1)
        return memo[day][prev];
    int maxPoints = 0;
    for(int act = 0; act < 3; act++) {
        if(act != prev){
            int pts = points[day][act] + solveMemo(day + 1,n,points,act,memo);
            maxPoints = max(maxPoints,pts);
        }
    }
    return memo[day][prev] = maxPoints;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
   vector<vector<int>> memo(n,vector<int> (4,-1)); 
   // return solveMemo(0,n,points,3,memo); //3 is just telling that for the first day i can choose any out of 0,1, and 2
   // return solveTabulation(n,points);
   return solveSpaceOptimization(n,points);
}
int main() {
	init_code();
	vector<vector<int>> points = {{1,2,5},{3,1,1}, {3,3,3}};
	cout<< ninjaTraining(points.size(),points);
	return 0;
}
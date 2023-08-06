// Imp Points: 
// we will use base cases to filer and keep track of distinct songs 

// we will keep track of mainly two things the goal and the distinct songs so far (oldSongs);

// 1 , 2 , 1
//    | |     >> this gap has to be k before repeating any oldsong (if k == 1)
   
// 1,2,3,4

// here if k = 3, them
// 	the number of choices we have for the 5th song will be (oldSongs - k) i.e i can only put a one here
	
// 	we will keep track of oldSongs: the songs which have been played previously (distinct);

// 1,2,3,4,1,2,3,4 
// 				>> here again oldSongs = 4 (distinct) so now choice will be k-oldSongs i.e only 1 song 
	

	
// -----------

// if n = 2, k = 0, goal = 3

// i can choose either for a start
// 		1     2
		
// now my number of old songs become 1;


// ----------
//How many new songs do i actually have available to choos 
// as that is what we should multiply the subproblem on line 71

//at line 75

// 	when we choose an old songs (repeat a songs)
//what is the number of songs i can choose from that is nothing but
//distOldSongs - k 
// if k == 0 then we can pick from any of the song, but if not then
//we have to skip at least k songs

//but we also need the gap to be k
//thats why we have the if condition


#include "bits/stdc++.h"
#include "Solution.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
long long mod = 1e9 + 7;

//TC : O(n * goal); SC: O(n * goal);
int solveRecursion(int currGoal, int distOldSongs, int &n, int &k) {
	// base cases
        if(currGoal == 0 && distOldSongs == n)
            return 1;
        if(currGoal == 0 or distOldSongs > n)
            return 0;

        int cnt = 0;
        //Choices
        //Choose a new song 
        cnt +=  ((n - distOldSongs) * solveRecursion(currGoal - 1, distOldSongs + 1,n,k)) % mod;

        //Choose an old song
        if(distOldSongs > k)
            cnt += ((distOldSongs- k) * (solveRecursion(currGoal - 1, distOldSongs,n,k))) % mod;
        
        cnt %= mod;

        return cnt;
}

//MEMOIZATION

vector<vector<long long>> dp;
long long solveMemo(int currGoal, int distOldSongs, int &n, int &k) {
        //base cases
        if(currGoal == 0 && distOldSongs == n)
            return 1;
        if(currGoal == 0 or distOldSongs > n)
            return 0;

        if(dp[distOldSongs][currGoal] != -1) return dp[distOldSongs][currGoal];
        long long cnt = 0;
        //Choices
        //Choose a new song 
        cnt +=  ((n - distOldSongs) * (solveMemo(currGoal - 1, distOldSongs + 1,n,k)) % mod) % mod;

        //Choose an old song
        if(distOldSongs > k)
            cnt += ((distOldSongs- k) * (solveMemo(currGoal - 1, distOldSongs,n,k)) %mod ) % mod;
        
        cnt %= mod;

        return dp[distOldSongs][currGoal] = int(cnt);
        }
int numPlaylists(int n, int k, int goal){
	dp.resize(n+1,vector<long long>(goal+1,-1));
	return solveMemo(goal,0,n,k);
}

int main() {
	init_code();
	Solution solution;
	int n, k, goal;
	cin >>n >> k >> goal;
	cout << numPlaylists(n,k,goal);

	return 0;
}
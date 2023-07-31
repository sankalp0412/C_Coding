// Given two strings s1 and s2, return the lowest ASCII
 // sum of deleted characters to make two strings equal.
#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}

map<pair<int,int> ,int> savedResult;

int solveRecursion(string s1, string s2,int i, int j) {
        if(i < 0){
            int deleteCost = 0;
            for(int it = 0; it <= j; it++) {
                deleteCost += (int)s2[it];
            }
        return deleteCost;
        }
        if(j < 0){
            int deleteCost = 0;
            for(int it = 0; it <= i; it++) {
                deleteCost += (int)s1[it];
            }
        return deleteCost;
        }

        if(s1[i] == s2[j]) {
            return solveRecursion(s1,s2,i-1,j-1);
        }
        else{
            return min((int)s1[i] + solveRecursion(s1,s2,i-1,j), min((int)s2[j] + solveRecursion(s1,s2,i,j-1), (int)s1[i] + (int)s2[j] + solveRecursion(s1,s2,i-1,j-1)));
        }
    }

    //Since there are two state variables i and j, we can use a
 // two-dimensional array to store the result of each sub-problem.
 int solveDPTopDown(string s1, string s2, int i, int j) {
 	if (i < 0 && j < 0) {
            return 0;
        }

        // If already computed, then return the result from the hash map
        pair<int, int> key = make_pair(i, j);
        if (savedResult.find(key) != savedResult.end()) {
            return savedResult[key];
        }
        
        // If any one string is empty, delete all characters of the other string
        if (i < 0) {
            savedResult[key] = s2[j] + solveDPTopDown(s1, s2, i, j-1);
            return savedResult[key];
        }
        if (j < 0) {
            savedResult[key] = s1[i] + solveDPTopDown(s1, s2, i-1, j);
            return savedResult[key];
        }
        
        // Call sub-problem depending on s1[i] and s2[j]
        // Save the computed result.
        if (s1[i] == s2[j]) {
            savedResult[key] = solveDPTopDown(s1, s2, i-1, j-1);
        } else {
            savedResult[key] = min(
                s1[i] + solveDPTopDown(s1, s2, i-1, j),
                s2[j] + solveDPTopDown(s1, s2, i, j-1)
            );
        }
        return savedResult[key];
 }   

 int solveDPBottomUp(string s1, string s2) {
 	 int m = s1.length(), n = s2.length();
        vector<vector<int>> computeCost(m + 1, vector<int>(n + 1, 0));

        // Fill in the base case values
        for (int i = 1; i <= m; i++) {
            computeCost[i][0] = computeCost[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= n; j++) {
            computeCost[0][j] = computeCost[0][j - 1] + s2[j - 1];
        }

        // Fill the remaining cells using the Bellman Equation
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    computeCost[i][j] = computeCost[i - 1][j - 1];
                } else {
                    computeCost[i][j] = min(
                        s1[i - 1] + computeCost[i - 1][j],
                        s2[j - 1] + computeCost[i][j - 1]
                    );
                }
            }
        }

        // Return the answer for entire input strings
        return computeCost[m][n];
 }
int solve(string s1, string s2) {
        if(s1 == s2) return 0;
        // return solveRecursion(s1,s2,s1.length()-1,s2.length()-1);
        // return solveDPTopDown(s1,s2,s1.length()-1,s2.length()-1);
        return solveDPBottomUp(s1,s2);
    }


int main() {
	init_code();
	string s1 = "sea", s2 = "eat";
	cout << solve(s1,s2);

	return 0;
}


// In other words, if s1[i] != s2[j], then the cost will be the minimum of these three sub-problems.

// ASCII value of s1[i] + cost to make s1[0...i-1] and s2[0...j] equal
// ASCII value of s2[j] + cost to make s1[0...i] and s2[0...j-1] equal
// ASCII value of s1[i] + ASCII value of s2[j] + cost to make s1[0...i-1] and s2[0...j-1] equal
// This breaking down of problems into smaller sub-problems can be easily done using recursion.

// Will our algorithm terminate?
// At any point in time, we are making at least one string smaller. Thus, we will reach a point where some string will become empty. So, our algorithm will terminate.

// But we need to define what to do when it is in the terminating condition. This is called as base condition.

// What will be the base condition?

// What if s1 reduces to an empty string? In this case, we need to delete all characters of s2[0...j]. Thus, the cost will be the sum of ASCII values of all characters of s2[0...j].
// What if s2 reduces to an empty string? In this case, we need to delete all characters of s1[0...i]. Thus, the cost will be the sum of ASCII values of all characters of s1[0...i].
// What if both s1 and s2 reduces to an empty string? In this case, we don't need to delete any character. Thus, cost will be zero.

// Time complexity: O(3^K * K)

// For each character of s, we recursively explore three possibilities. Either we can delete this character from s, or from another string, or we can delete both characters. Thus, we have three recursive calls for each character of s. Hence, there will be 3K3^{K}3 
// K
//   recursive calls.

// The time complexity of each recursive call is O(K)O(K)O(K) because we may need to traverse the complete string to calculate the cost.

// Thus, the total time complexity will be O(3K⋅K)O(3^{K} \cdot K)O(3 
// K
//  ⋅K).

// Space complexity: O(K)O(K)O(K).

// The space complexity will be O(K)O(K)O(K) because of the recursion stack. The recursive process will terminate when either of the strings becomes empty. Thus, the maximum depth of the recursion tree will be KKK
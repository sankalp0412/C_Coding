#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    void dfs(vector<NestedInteger>::iterator begin,vector<NestedInteger>::iterator end) {
        for(auto it = begin; it != end; it++) {
            if(it -> isInteger())
                q.push(it -> getInteger());
            else 
                dfs(it -> getList().begin(), it -> getList().end());
        }
    }
    
    queue<int> q;
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList.begin(),nestedList.end());   
    }
    
    int next() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main() {
	init_code();
	// vector<> nestedList = {{1,1},2,{1,1}};
	// NestedIterator i(nestedList);
    // while (i.hasNext()) cout << i.next();
	return 0;
}

//Can't test and run this code yet.
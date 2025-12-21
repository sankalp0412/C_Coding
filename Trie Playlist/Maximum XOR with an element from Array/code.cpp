#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class TrieNode{
    public:
        TrieNode *links[2] = {nullptr};
        
        ~TrieNode(){
            for(auto &p: links) delete p;
        }
};

class Trie{
    public:
        TrieNode *root;
        Trie() {
            root = new TrieNode();
        }
        ~Trie() {
            delete root;
        }
        void insert(int &num) {
            auto curr = root;
            for(int i = 31; i >= 0; i--) {
                auto bit = (num >> i) & 1;
                if(curr -> links[bit] == nullptr) {
                    curr -> links[bit] = new TrieNode();
                }
                curr = curr -> links[bit];
            }
        }
        int getMaxXor(int &num) {
            uint32_t ans = 0;
            auto curr = root;
            for(int i = 31; i >= 0; i--) {
                auto currBit = (num >> i) & 1;
                auto requiredBit = !currBit;
                if(curr-> links[requiredBit] != nullptr) {
                    curr = curr -> links[requiredBit];
                    ans = ans | (1 << i);
                }
                else 
                curr = curr -> links[!requiredBit];
            }
            return ans;
        }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m,-1);
        vector<pair<int,pair<int,int>>> qs;
        // {i,{xi,ai}}
        for(int i = 0; i <m;  i++) {
            qs.push_back({queries[i][1],{queries[i][0],i}});
        }
        //O(mlogm)
        sort(qs.begin(),qs.end());

        Trie trie;


        int currIdx = 0;
        //O(m * 32 + n * 32);
        for(auto q: qs) {
            int originalIndex = q.second.second;
            int xi = q.second.first;
            int ai = q.first;

            while(currIdx < n && nums[currIdx] <= ai){
                trie.insert(nums[currIdx++]);
            }
            if(currIdx == 0)
                continue;
            int maxXorforCurrent = trie.getMaxXor(xi);
            ans[originalIndex]= maxXorforCurrent;
        }
        return ans;
    }
};
int main() {
	init_code();
    Solution sol;
    vector<int> nums = {5,2,4,6,6,3};
    vector<vector<int>> queries = {{12,4}, {8,1}, {6,3}};
    vector<int> result = sol.maximizeXor(nums, queries);
    for (int r : result) {
        cout << r << " ";
    }
	return 0;
}
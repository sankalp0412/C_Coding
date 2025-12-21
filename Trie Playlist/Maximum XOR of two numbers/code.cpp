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
        TrieNode* links[2] = {nullptr};
    ~TrieNode() {
        for(auto &p: links)
            delete p;
    }
};
class Trie{
    public: 
        TrieNode * root;
        Trie() {
            root = new TrieNode();
        }
        ~Trie(){
            delete root;
        }

        void insert(int &num){
            auto curr = root;
            for(int i = 31; i>= 0; i--) {
                auto currBit = (num >> i) & 1;
                if(curr -> links[currBit] == nullptr){
                    curr -> links[currBit] = new TrieNode();
                }
                curr = curr -> links[currBit];
            }
        }

        int getMaxXor(int &num) {
            int maxXor = 0;
            auto curr = root;
            for(int i = 31; i >= 0; i--) {
                auto currBit = (num >> i) & 1;
                auto requiredBit = !currBit;
                if(curr -> links[requiredBit] != nullptr){
                    //i can make this bit 1 in the final or
                    curr = curr -> links[requiredBit];
                    maxXor |= (1 << i);
                }
                else {
                    curr = curr -> links[!requiredBit];
                }
            }
            return maxXor;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie;
        for(int i = 0; i < n; i++) {
            trie.insert(nums[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, trie.getMaxXor(nums[i]));
        }
        return ans;
    }
};
int main() {
	init_code();
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    Solution solution;
    cout << solution.findMaximumXOR(nums);
	return 0;
}
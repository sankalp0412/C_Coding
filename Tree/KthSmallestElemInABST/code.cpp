#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class Solution {
public:
    bool diffByOne(string a, string b) {
        int binA = 0, binB = 0;
        for(int i = 0; i < a.size(); i++) {
            auto curr = a[i];
            int shifts = curr - 'a';
            binA |= 1 << shifts;
        }
        for(int i = 0; i < b.size(); i++) {
            auto curr = b[i];
            int shifts = curr - 'a';
            binB |= 1 << shifts;
        }
        
        auto res = binA ^ binB;
        return __builtin_popcount(res) == 2;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(auto &word: wordList)
            mp[word] = -1;
        
        if(!mp.count(endWord)) return 0;
        
        if(!mp.count(beginWord))
        wordList.push_back(beginWord);
        
        int n = wordList.size();
        unordered_map<string,vector<string>> graph;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                string u = wordList[i];
                string v = wordList[j];

                if(diffByOne(u,v)){
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
            }
        }
        for (auto &entry : graph) {
            cout << entry.first << ": ";
            for (auto &neighbor : entry.second) {
            cout << neighbor << " ";
            }
            cout << endl;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()) {
            auto currWord = q.front().first;
            auto length = q.front().second;
            q.pop();
            if(currWord == endWord) return length;
            mp[currWord] = 1; //visited
            for(auto &adjWord: graph[currWord]) {
                if(mp[adjWord] == -1) {
                    //we havet explored this word yet
                    q.push({adjWord,length+1});
                }
            }

        }

        return 0;
    }
};
int main() {
	init_code();
    Solution sol;
    vector<string> wordList = {"most", "mist", "miss", "lost", "fist", "fish"};
    int ans = sol.ladderLength("lost","miss",wordList);
    return 0;
}
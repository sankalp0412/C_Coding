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
        TrieNode *links[26] = {nullptr};
        bool endsWith = false;

        ~TrieNode() {
            for(auto &p: links) {
                delete p;
            }
        }
};
class Trie{
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        ~Trie() {
            delete root;
        }

        void insert(string &word) {
            TrieNode *curr = root;
            for(auto &ch : word) {
                if(curr -> links[ch - 'a'] == nullptr){
                    curr -> links[ch-'a'] = new TrieNode();
                }
                curr = curr -> links[ch - 'a'];
            }
            curr -> endsWith = true;
        }
        bool checkStringExists(string &str) {
            auto curr = root;
            for(auto &ch: str) {
                if(curr -> links[ch - 'a'] == nullptr)
                    return false;
                curr = curr -> links[ch-'a'];
            }
           
            return curr -> endsWith;
        }
        bool checkAllPrefixesExist(string &word) {
            string prefix = "";
            for(auto &ch: word) {
                prefix += ch;
                if(!this -> checkStringExists(prefix))
                return false;
            }
            return true;
        }
};
string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto &word: a) {
        trie.insert(word);
    }
    string ans ="";
    for(auto &word: a) {
        if(trie.checkAllPrefixesExist(word)){
            if(ans == "") ans = word;
            else if(ans.length() == word.length()) 
                ans = ans < word ? ans: word;
            
            else if(ans.size() < word.size())
                ans = word;
        }
    }

    return ans == "" ? "None" : ans;
}
int main() {
	init_code();
    vector<string> words = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    cout << completeString(words.size(), words) << endl;
return 0;
}

//TC : O(n) * O(m) where m is the average lenght of all strings
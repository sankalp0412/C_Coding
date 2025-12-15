#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
class TrieNode {
    public:
        TrieNode* links[26] = {nullptr};
        int endsWith = 0;
        int prefixCount = 0;
        ~TrieNode() {
            for(auto &p: links)
                delete p;
        }
};
class Trie{

    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode(); 
    }
    ~Trie() {delete root;} 

    void insert(string word){
        TrieNode *curr = root;
        for(auto &ch: word){
            if(curr -> links[ch - 'a'] == nullptr) {
                //creat a new TrieNode
                curr -> links[ch-'a'] = new TrieNode();
            }
            curr = curr -> links[ch - 'a'];
            curr -> prefixCount++;
        }
        curr -> endsWith++;
    }

    int countWordsEqualTo(string word){
        TrieNode *curr = root;
        for(auto &ch: word) {
            if(curr -> links[ch - 'a'] == nullptr) 
                return 0;
            else
                curr = curr -> links[ch - 'a'];
        }
        return curr -> endsWith;
    }

    int countWordsStartingWith(string word){
        TrieNode *curr = root;
        for(auto &ch: word) {
            if(curr -> links[ch - 'a'] == nullptr) 
                return 0;
            else
                curr = curr -> links[ch - 'a'];
        }
        return curr -> prefixCount;
    }

    void erase(string word){
        TrieNode *curr = root;
        for(auto &ch: word) {
            curr = curr -> links[ch - 'a'];
            curr -> prefixCount--;
        }
        curr -> endsWith--;
        if (curr -> prefixCount == 0)
           curr = nullptr; //the node is not requried.
    }
};

int main() {
	init_code();
    Trie trie;
    trie.insert("samsung");
    trie.insert("samsung");
    trie.insert("vivo");
    trie.erase("vivo");
    cout << trie.countWordsStartingWith("sam") << endl;
    cout << trie.countWordsEqualTo("vivo");
	return 0;
}
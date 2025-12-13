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
    bool wordEnd = false;
    ~TrieNode()  {
        for (auto &p: links) {
            delete p;
        }
    }
};
class Trie {
public:
    TrieNode* root;

    Trie() : root(new TrieNode()) {}
    ~Trie() {delete root;}
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto &ch: word) {
            if(curr -> links[ch-'a'] == nullptr) {
                curr -> links[ch - 'a'] = new TrieNode();
            }
            curr = curr -> links[ch-'a'];
        }
        curr -> wordEnd= true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(auto &ch : word) {
            if(curr -> links[ch - 'a'] == nullptr)
                return false;
            curr = curr -> links[ch-'a'];
        }
        return curr -> wordEnd == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(auto &ch : prefix) {
            if(curr -> links[ch - 'a'] == nullptr)
                return false;
            curr = curr -> links[ch-'a'];
        }
        return true;
    }
};

int main() {
	init_code();
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple");
    cout << obj->search("app");
    cout << obj->startsWith("app");
    obj->insert("app");
    cout << obj->search("app");
	return 0;
}
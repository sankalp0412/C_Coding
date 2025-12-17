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
			for(auto &p: links) 
				delete p;
		}
};
class Trie {
	public:
		TrieNode *root;
		Trie(){
			root = new TrieNode();
		}
		~Trie() {
			delete root;
		}

		bool insert(string &word) {
			auto curr = root;
		
			for(auto &ch: word) {
				if(curr -> links[ch- 'a'] == nullptr) {
					curr -> links[ch-'a'] = new TrieNode();
				}
				curr = curr -> links[ch - 'a'];
			}
			bool insertNew = curr -> endsWith;
			curr -> endsWith = true;
			return !insertNew;
		}
};	
int countDistinctSubstrings(string &s){
	int n = s.size();
	Trie trie;
	string temp = "";
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		temp.clear();
		for(int j = i; j < n; j++) {
			temp += s[j];
			if(trie.insert(temp))
				ans++;
		}
	}
	return ans + 1;
}
int main() {
	init_code();
	string s = "abcde";
    cout << countDistinctSubstrings(s) << endl;
	return 0;
}
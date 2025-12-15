#include "bits/stdc++.h"
using namespace std;

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("output.txt", "w", stderr);
#endif
}
// class TrieNode {
//     public:
//         TrieNode* links[26] = {nullptr};
//         bool endsWith = false;
//         ~TrieNode() {
//             for(auto &p: links) delete p;
//         }
// };

// class Trie{
//     public:
//         TrieNode *root;
//         Trie() {
//             root = new TrieNode();
//        }
//         ~Trie() {
//             delete root;
//         }
    
//         void insert(const string& word) {
//             TrieNode *curr = root;
//             for(auto &ch: word) {
//                 if(curr -> links[ch - 'a'] == nullptr){
//                     curr -> links[ch-'a'] = new TrieNode();
//                 }
//                 curr = curr -> links[ch-'a'];
//             }
//             curr -> endsWith = true;
//         }
// };

// class Solution {
// public:
//     void dfs(int i , int j,vector<vector<char>>& board, TrieNode *curr, unordered_set<string> &ans,string &temp, int &m, int &n) {
//         if(curr->endsWith == true){
//             ans.insert(temp);
//             curr->endsWith = false;
//         }
//         char c = board[i][j];
//         board[i][j] = '#';
        
//         vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
//         for(auto &dir: directions) {
//             int x = i+ dir[0];
//             int y = j+dir[1];
            
//             if(x >= 0 && y >= 0 && x < m && y < n && board[x][y] != '#') {
//                 auto nextChar = curr -> links[board[x][y] - 'a'];
//                 if(nextChar == nullptr) continue;
//                 temp += board[x][y];
//                 dfs(x,y,board,nextChar,ans,temp,m,n);
//                 temp.pop_back();
                
//             }    
           
//         }
        
//         board[i][j] = c;
//     }
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         int m =board.size(), n = board[0].size();
//         Trie trie;
//         for(auto &word: words) {
//             trie.insert(word);
//         }
//         unordered_set<string> ans;


//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 auto curr =trie.root;
                
//                 string temp = "";
//                 temp += board[i][j];
//                 if(curr -> links[board[i][j] - 'a'] != nullptr)
//                     dfs(i,j,board,curr -> links[board[i][j] - 'a'],ans,temp,m,n);
                
//             }
//         }
//         vector<string> res(ans.begin(),ans.end());
//         return res;
//     }
// };
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word = false;
    ~TrieNode() {
        for (auto &p : children) delete p.second;
    }
};

struct Trie {
    TrieNode* root;
    Trie() : root(new TrieNode()) {}
    ~Trie() { delete root; }

    void insert(const string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->is_end_of_word = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty() || words.empty()) return {};

        Trie trie;
        for (auto &w : words) trie.insert(w);

        int rows = (int)board.size();
        int cols = (int)board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        unordered_set<string> result_set;
        string path;
        path.reserve(32);

        function<void(int,int,TrieNode*)> backtrack = [&](int r, int c, TrieNode* node) {
            if (node->is_end_of_word) {
                result_set.insert(path);
                node->is_end_of_word = false; 
            }

            visited[r][c] = true;
            static const int DIRS[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
            for (auto &d : DIRS) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (visited[nr][nc]) continue;
                char next_char = board[nr][nc];
                auto it = node->children.find(next_char);
                if (it != node->children.end()) {
                    path.push_back(next_char);
                    backtrack(nr, nc, it->second);
                    path.pop_back();
                }
            }
            visited[r][c] = false;
        };

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                char start = board[r][c];
                auto it = trie.root->children.find(start);
                if (it != trie.root->children.end()) {
                    path.clear();
                    path.push_back(start);
                    backtrack(r, c, it->second);
                }
            }
        }
        vector<string> result(result_set.begin(), result_set.end());
        return result;
    }
};
int main() {
	init_code();
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    Solution solution;
    vector<string> result = solution.findWords(board, words);
    for (const auto& word : result) {
        cout << word << endl;
    }
    return 0;
}

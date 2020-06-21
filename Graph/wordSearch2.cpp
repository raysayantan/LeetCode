/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or 
vertically neighboring. The same letter cell may not be used more than once in a word.
Example:
Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Note:
All inputs are consist of lowercase letters a-z.
The values of words are distinct.
Accepted
*/
class Solution {
    struct Trie{
        bool isWord;
        vector<Trie*> next;
        Trie(): next(26,NULL){
            isWord = false;
        }
    };
    int rows, cols;
    unordered_set<string> s;
    vector<string> result;
public:
    Trie* constructTrie(vector<string>& words){
        Trie* root = new Trie();
        Trie* p;
        int wc = words.size();
        for(int i = 0; i < wc; i++){
            string word = words[i];
            p = root;
            for(int k = 0; k < word.length(); k++){
                if(p->next[word[k] - 'a'] == NULL){
                    p->next[word[k] - 'a'] = new Trie();
                }
                p = p->next[word[k] - 'a'];
            }
            p->isWord = true;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, Trie* root, int i, int k, string word){
        if( i < 0 || i >= rows || k < 0 || k >= cols || board[i][k] == '#' || !root->next[board[i][k] - 'a']){         
            return;
        }
        char ch = board[i][k];
        board[i][k] = '#';
        Trie* p = root->next[ch - 'a'];
        word += ch;
        if(p->isWord == true && s.find(word) == s.end()){
            s.insert(word);
            result.push_back(word);
        }
        
        dfs(board, p, i-1, k, word);
        dfs(board, p, i, k-1, word);
        dfs(board, p, i+1, k, word);
        dfs(board, p, i, k+1, word);
        
        board[i][k] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        if(rows == 0)
            return result;
        cols = board[0].size();
        if(cols == 0)
            return result;
        Trie* root = constructTrie(words);
        for(int i = 0; i < rows; i++){
            for(int k = 0; k < cols; k++){
                string word = "";
                if(root->next[board[i][k] - 'a'] != NULL)
                    dfs(board, root, i, k, word);
            }
        }
        return result;
    }
};

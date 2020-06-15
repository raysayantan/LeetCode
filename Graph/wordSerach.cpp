/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or 
vertically neighboring. The same letter cell may not be used more than once.
Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
Constraints:
board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/
class Solution {
    int rows;
    int cols;
    set<pair<int,int>> tracker;
    bool findPattern(vector<vector<char>>& board, string word, bool &found, pair<int,int> pos, int idx){
        int row = pos.first;
        int col = pos.second;
        bool status = false;
        if(found)
            return found;
        if(idx == word.length() - 1){
            if(word[idx] == board[row][col]){
                found = true;
                return true;
            } else {
                return false;
            }
        }
        
        if(word[idx] == board[row][col]){
            if((row - 1 >= 0) && tracker.find(make_pair(row - 1,col)) == tracker.end()){
                tracker.insert(make_pair(row - 1,col));
                status |= findPattern(board, word, found, make_pair(row-1, col), idx+1);
                tracker.erase(make_pair(row - 1,col));
            }
            if((col - 1 >= 0) && tracker.find(make_pair(row,col - 1)) == tracker.end()){
                tracker.insert(make_pair(row,col-1));
                status |= findPattern(board, word, found, make_pair(row, col-1), idx+1);
                tracker.erase(make_pair(row,col-1));
            }
            if((row + 1 < rows) && tracker.find(make_pair(row+1,col)) == tracker.end()){ 
                tracker.insert(make_pair(row+1,col));
                status |= findPattern(board, word, found, make_pair(row+1, col), idx+1);
                tracker.erase(make_pair(row + 1,col));
            }
            if((col + 1 < cols) && tracker.find(make_pair(row,col+1)) == tracker.end()){
                tracker.insert(make_pair(row, col+1));
                status |= findPattern(board, word, found, make_pair(row, col+1), idx+1);
                tracker.erase(make_pair(row,col + 1));
            }
        } else{
            return false;
        }
        
        return status;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        if(rows == 0) return false;
        cols = board[0].size();
        bool found = false;
        bool status = false;        
        for(int i = 0; i < rows; i++){
            for(int k = 0; k < cols; k++){
                if(board[i][k] == word[0]){
                    tracker.insert(make_pair(i,k));
                    status = findPattern(board, word, found, make_pair(i,k), 0);
                    tracker.clear();
                    if(status)
                        return true;
                }
            }
        }
        return status;
    }
};

// Using map as the tracker and getting better space and time complexity
class Solution {
    int rows;
    int cols;
    map<pair<int,int>, bool> tracker;
    bool findPattern(vector<vector<char>>& board, string word, bool &found, pair<int,int> pos, int idx){
        int row = pos.first;
        int col = pos.second;
        bool status = false;
        if(found)
            return found;
        if(idx == word.length() - 1){
            if(word[idx] == board[row][col]){
                found = true;
                return true;
            } else {
                return false;
            }
        }
        
        if(word[idx] == board[row][col]){
            if((row - 1 >= 0) && (tracker.find(make_pair(row - 1,col)) == tracker.end()
                                 || tracker[make_pair(row - 1,col)] == false)){
                if(tracker.find(make_pair(row - 1,col)) == tracker.end())
                    tracker.insert({make_pair(row - 1,col),true});
                else
                    tracker[make_pair(row - 1,col)] = true;
                status |= findPattern(board, word, found, make_pair(row-1, col), idx+1);
                tracker[make_pair(row - 1,col)] = false;
                if(status) return status;
            }
            if((col - 1 >= 0) && (tracker.find(make_pair(row,col - 1)) == tracker.end()
                                 || tracker[make_pair(row,col-1)] == false)){
                if(tracker.find(make_pair(row,col - 1)) == tracker.end()){
                    tracker.insert({make_pair(row,col-1),true});
                } else {
                    tracker[make_pair(row,col-1)] = true;
                }
                status |= findPattern(board, word, found, make_pair(row, col-1), idx+1);
                tracker[make_pair(row,col-1)] = false;
                if(status) return status;
            }
            if((row + 1 < rows) && (tracker.find(make_pair(row+1,col)) == tracker.end()
                                   || tracker[make_pair(row+1,col)] == false)){ 
                if(tracker.find(make_pair(row+1,col)) == tracker.end()){
                    tracker.insert({make_pair(row+1,col), true});
                } else {
                    tracker[make_pair(row+1,col)] = true;
                }
                status |= findPattern(board, word, found, make_pair(row+1, col), idx+1);
                tracker[make_pair(row+1,col)] = false;
                if(status) return status;
            }
            if((col + 1 < cols) && (tracker.find(make_pair(row,col+1)) == tracker.end()
                                   || tracker[make_pair(row,col+1)] == false)){
                if(tracker.find(make_pair(row,col+1)) == tracker.end()){
                    tracker.insert({make_pair(row, col+1), true});
                } else {
                    tracker[make_pair(row,col+1)] = true;
                }
                status |= findPattern(board, word, found, make_pair(row, col+1), idx+1);
                tracker[make_pair(row,col+1)] = false;
                if(status) return status;
            }
        } else{
            return false;
        }
        
        return status;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        if(rows == 0) return false;
        cols = board[0].size();
        bool found = false;
        bool status = false;        
        for(int i = 0; i < rows; i++){
            for(int k = 0; k < cols; k++){
                if(board[i][k] == word[0]){
                    if(tracker.find(make_pair(i,k)) == tracker.end())
                        tracker.insert({make_pair(i,k), true});
                    else
                        tracker[make_pair(i,k)] = true;
                    status = findPattern(board, word, found, make_pair(i,k), 0);
                    tracker[make_pair(i,k)] = false;
                    if(status)
                        return true;
                }
            }
        }
        return status;
    }
};

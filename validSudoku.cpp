/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, vector<int>> row;
        map<char, vector<int>> col;
        map<char, vector<int>> block;        
        for(int i = 0; i < 9; i++){
            for(int k = 0; k < 9; k++){
                int c = (i%3)*3 + k%3;
                int r = (i/3)*3 + k/3;                
                if(board[r][c] == '.') continue;
                auto it = row.find(board[r][c]);
                if(it != row.end()){
                    vector<int> v = it->second;
                    for(auto it1 = v.begin(); it1 != v.end(); it1++){
                        if(*it1 == r) return false;
                    }
                    v.push_back(r);
                    row[board[r][c]] = v;
                } else {
                    row.insert({board[r][c], {r}});
                }
                it = col.find(board[r][c]);
                if(it != col.end()){
                    vector<int> v = it->second;
                    for(auto it1 = v.begin(); it1 != v.end(); it1++){
                        if(*it1 == c) return false;
                    }
                    v.push_back(c);
                    col[board[r][c]] = v;
                } else {
                    col.insert({board[r][c], {c}});
                }
                it = block.find(board[r][c]);
                if(it != block.end()){
                    vector<int> v = it->second;
                    for(auto it1 = v.begin(); it1 != v.end(); it1++){
                        if(*it1 == i) return false;
                    }
                    v.push_back(i);
                    block[board[r][c]] = v;
                } else {
                    block.insert({board[r][c], {i}});
                }
            }
        }        
        return true;
    }
};

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are 
connected if they are adjacent cells connected horizontally or vertically.
*/
class Solution {
    void markCell(vector<vector<char>>& board, pair<int, int> cell, int row, int col){
        //One cell have four neighbouring cells top, left, bottom and right
        //need to check its contents and if this is 'O' then we can move on that
        //and we will do BFS and mark this cell with I
        int i = cell.first;
        int k = cell.second;
        //top
        if(i-1 >= 0 && board[i-1][k] == 'O'){
            board[i-1][k] = 'I';
            markCell(board, make_pair(i-1,k),row,col);
        }
        //left
        if(k-1 >= 0 && board[i][k-1] == 'O'){
            board[i][k-1] = 'I';
            markCell(board, make_pair(i, k-1), row, col);
        }
        //bottom
        if(i+1 < row && board[i+1][k] == 'O'){
            board[i+1][k] = 'I';
            markCell(board, make_pair(i+1,k), row, col);
        }
        //right
        if(k+1 < col && board[i][k+1] == 'O'){
            board[i][k+1] = 'I';
            markCell(board,make_pair(i, k+1), row, col);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows <= 2) return;
        int cols = board[0].size();
        if(cols <= 2) return;
        //check 'O' in first row and mark all connected 'O'
        for(int i = 0; i < cols; i++){
            if(board[0][i] == 'O'){
                board[0][i] = 'I';
               if(i-1 >= 0 && board[0][i-1] == 'O'){
                   board[0][i-1] = 'I';
                   markCell(board, make_pair(0, i-1), rows, cols);
               }
                
               if(i+1 < cols && board[0][i+1] == 'O'){
                   board[0][i+1] = 'I';
                   markCell(board, make_pair(0, i+1), rows, cols);
               }
                
               if(board[1][i] == 'O'){
                   board[1][i] = 'I';
                   markCell(board, make_pair(1, i), rows, cols);
               }
            }
        }
        
        //check 'O' in first col and mark all connected 'O'
        for(int i = 0; i < rows; i++){
           if(board[i][0] == 'O'){
               board[i][0] = 'I';
               if(i-1 >= 0 && board[i-1][0] == 'O'){
                   board[i-1][0] = 'I';
                   markCell(board, make_pair(i-1, 0), rows, cols);
               }
                
               if(i+1 < rows && board[i+1][0] == 'O'){
                   board[i+1][0] = 'I';
                   markCell(board, make_pair(i+1, 0), rows, cols);
               }
                
               if(board[i][1] == 'O'){
                   board[i][1] = 'I';
                   markCell(board, make_pair(i, 1), rows, cols);
               }
            } 
        }
        
        //check 'O' in last row and mark all connected 'O'
        for(int i = 0; i < cols; i++){
            if(board[rows-1][i] == 'O'){
                board[rows-1][i] = 'I';
               if(i-1 >= 0 && board[rows-1][i-1] == 'O'){
                   board[rows-1][i-1] = 'I';
                   markCell(board, make_pair(rows-1, i-1), rows, cols);
               }
                
               if(i+1 < cols && board[rows-1][i+1] == 'O'){
                   board[rows-1][i+1] = 'I';
                   markCell(board, make_pair(rows-1, i+1), rows, cols);
               }
                
               if(board[rows-2][i] == 'O'){
                   board[rows-2][i] = 'I';
                   markCell(board, make_pair(rows-2, i), rows, cols);
               }
            }
        }
        
        //check 'O' in last col and mark all connected 'O'
        for(int i = 0; i < rows; i++){
            if(board[i][cols-1] == 'O'){
                board[i][cols-1] = 'I';
               if(i-1 >= 0 && board[i-1][cols-1] == 'O'){
                   board[i-1][cols-1] = 'I';
                   markCell(board, make_pair(i-1, cols-1), rows, cols);
               }
                
               if(i+1 < rows && board[i+1][cols-1] == 'O'){
                   board[i+1][cols-1] = 'I';
                   markCell(board, make_pair(i+1, cols-1), rows, cols);
               }
                
               if(board[i][cols-2] == 'O'){
                   board[i][cols-2] = 'I';
                   markCell(board, make_pair(i, cols-2), rows, cols);
               }
            }
        }
        
        //Now traverse through the matrix and make all the 'I' with 'O', as this
        //are connected with a cell having 'O' at the edge and can not be marked 'X'
        for(int i = 0; i < rows; i++){
            for(int k = 0; k < cols; k++){
                if(board[i][k] == 'I'){
                    board[i][k] = 'O';
                } else if(board[i][k] == 'O'){
                    board[i][k] = 'X';
                }
            }
        }
    }
};

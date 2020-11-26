/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/
class Solution {
    int rows;
    int cols;
    bool helper(int time, vector<vector<int>> &grid){
        bool isContinue = false;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == time){
                    isContinue = true;
                    //left
                    if(c > 0){
                        if(grid[r][c - 1] == 1){
                            grid[r][c - 1] = time + 1;
                        }
                    }
                    
                    //top
                    if(r > 0){
                        if(grid[r - 1][c] == 1){
                            grid[r - 1][c] = time + 1;
                        }
                    }
                    
                    //right
                    if(c + 1 < cols){
                        if(grid[r][c + 1] == 1){
                            grid[r][c + 1] = time + 1;
                        }
                    }
            
                    //bottom
                    if(r + 1 < rows){
                        if(grid[r + 1][c] == 1){
                            grid[r + 1][c] = time + 1;
                        }
                    }
                }
            }
        }
        
        return isContinue;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int total = 2;
        while(helper(total, grid)){
            total++;
        }    
        total = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    return -1;
                }
                
                total = max(total, grid[r][c]);
            }
        }
        
        if(total >= 2) 
            total = total - 2;
        
        return total;
    }
};

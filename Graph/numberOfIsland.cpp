/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/
class Solution {
    int rows;
    int cols;
    void dfsHelper(vector<vector<char>>& grid, int row, int col){
        if(grid[row][col] == '1'){
            grid[row][col] = '2';
            
            //left
            if(col > 0){
                dfsHelper(grid, row, col -1);
            }
            
            //top
            if(row > 0){
                dfsHelper(grid, row - 1, col);
            }
            
            //right
            if(col < cols - 1){
                dfsHelper(grid, row, col + 1);
            }
            
            //bottom
            if(row < rows - 1){
                dfsHelper(grid, row + 1, col);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        rows = grid.size();
        if(rows == 0)
            return counter;
        cols = grid[0].size();
        if(cols == 0)
            return counter;
        
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == '1'){
                    counter++;
                    dfsHelper(grid, row, col);
                }
            }
        }
        
        return counter;
    }
};

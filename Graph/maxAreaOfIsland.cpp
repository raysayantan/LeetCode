/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/
class Solution {
    int rows;
    int cols;
    void helper(vector<vector<int>>& grid, int &len, int r, int c){
        if(grid[r][c] == 1){
            grid[r][c] = len;
            
            if(c > 0 && grid[r][c - 1] == 1){
                helper(grid, ++len, r, c - 1);
            }
            
            if(r > 0 && grid[r - 1][c] == 1){
                helper(grid, ++len, r - 1, c);
            }
            
            if(c < cols - 1 && grid[r][c + 1] == 1){
                helper(grid, ++len, r, c + 1);
            }
            
            if(r < rows - 1 && grid[r + 1][c] == 1){
                helper(grid, ++len, r + 1, c);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        int maxlen = 0;
        if( rows == 0){
            return 0;
        }
        
        cols = grid[0].size();
        if(cols == 0){
            return 0;
        }
        
        int len = 2;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    helper(grid, len, r, c);
                    maxlen = max(maxlen, len - 1);
                }
                
                len = 2;
            }
        }
        
        return maxlen;
    }
};

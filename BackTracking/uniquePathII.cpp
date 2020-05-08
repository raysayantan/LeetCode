/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/
class Solution {
    int uniquePathsUtil(vector<vector<int>>& obstacleGrid, int row, int col){
        int top = 0;
        int left = 0;
        
        if(obstacleGrid[row][col] == 1)
            return 0;
        if(row == 0 && col == 0)
            return 1;
        if(row - 1 >= 0){
            if(obstacleGrid[row-1][col] != 1){
                if(abs(obstacleGrid[row-1][col]) > 0){
                    top = abs(obstacleGrid[row-1][col]);
                } else {
                    top = uniquePathsUtil(obstacleGrid, row - 1, col);
                }
            } else {
                top = 0;
            }
        }
        
        if(col - 1 >= 0){
            if(obstacleGrid[row][col - 1] != 1){
                if(abs(obstacleGrid[row][col - 1]) > 0){
                    left = abs(obstacleGrid[row][col - 1]);
                } else {
                    left = uniquePathsUtil(obstacleGrid, row, col - 1);
                }
            } else {
                left = 0;
            }
        }
        //cout<<row<<":"<<col<<"-"<<top<<" "<<left<<endl;
        obstacleGrid[row][col] = -(top+ left);
        return left + top;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int numRow = obstacleGrid.size();
        if(numRow == 0) return 0;
        int numCol = obstacleGrid[0].size();
        
        return uniquePathsUtil(obstacleGrid, numRow - 1, numCol - 1);
    }
};

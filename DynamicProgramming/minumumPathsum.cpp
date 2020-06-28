/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
    //Idea is to use DFS to traverse all the path and store the min val of all the possible values from curr pos to the destination
    int minDistPath(vector<vector<int>>& grid, map<pair<int,int>,int>& minDist, pair<int,int> finalPos, pair<int,int> currPos){
        int minVal = INT_MAX;
        //if we have data in the map table of the min value from curr pos to the destination
        if(minDist.find(currPos) != minDist.end()){
            return minDist[currPos];
        }
        
        //if we reached to the destination i.e. bottom right
        if(currPos == finalPos){
            minDist.insert({currPos, grid[finalPos.first][finalPos.second]});
            return grid[finalPos.first][finalPos.second];
        }
        int downDist = INT_MAX;
        int rightDist = INT_MAX;
        //move to the bottom
        if(currPos.first + 1 <= finalPos.first){
            downDist = minDistPath(grid, minDist, finalPos, make_pair(currPos.first + 1, currPos.second));
        }
        
        //move to the right
        if(currPos.second + 1 <= finalPos.second){
            rightDist = minDistPath(grid, minDist, finalPos, make_pair(currPos.first, currPos.second+1));
        }
        
        //find the minimum value in the current position and record in the map
        minVal = min(downDist, rightDist);
        if(minDist.find(currPos) != minDist.end()){
            minVal = min(minVal+ grid[currPos.first][currPos.second], minDist[currPos]);
            minDist[currPos] = minVal;
        } else{
            minDist.insert({currPos, minVal + grid[currPos.first][currPos.second]});
        }
        return minVal + grid[currPos.first][currPos.second];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        //Storing the min distance to bottom right from a point
        map<pair<int,int>, int> minDist;
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        if(cols == 0)
            return 0;
        pair<int, int> finalPos = make_pair(rows - 1, cols - 1);
        int dist = minDistPath(grid, minDist, finalPos, make_pair(0,0));
        return dist;
    }
};

/*
Given a rows * columns matrix mat of ones and zeros, return how many submatrices have all ones.
Example 1:

Input: mat = [[1,0,1],
              [1,1,0],
              [1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
Example 2:

Input: mat = [[0,1,1,0],
              [0,1,1,1],
              [1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3. 
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2. 
There are 2 rectangles of side 3x1. 
There is 1 rectangle of side 3x2. 
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
Example 3:

Input: mat = [[1,1,1,1,1,1]]
Output: 21
Example 4:

Input: mat = [[1,0,1],[0,1,0],[1,0,1]]
Output: 5
 

Constraints:

1 <= rows <= 150
1 <= columns <= 150
0 <= mat[i][j] <= 1
*/
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int total = 0;
        int rows = mat.size();
        if(rows == 0)
            return total;
        int cols = mat[0].size();
        if(cols == 0)
            return total;
        vector<vector<int>> tracker(rows, vector<int>(cols,0));
        //first count the consecutive one's at right side direction
        //suppose for the array [0,1,1,1,0,1,1] this loop will make
        //[0,3,2,1,0,2,1] and will be used in the loop below
        for(int i = 0; i < rows; i++){
            for(int k = cols - 1; k >= 0; k--){
                if(mat[i][k] != 1)
                    continue;
                if(k != cols - 1){
                    tracker[i][k] = tracker[i][k + 1] + 1;
                } else {
                    tracker[i][k] = mat[i][k];
                }
            }
        }
        
        //on bottom direction and diagonal. Suppose we have two adjacent rows i and i+1
        //have values at jth column x and y, then we will find the min(x,y) which means
        //(i,j) has x consecutive one at its right and same for (i+1, j) is y. so the diagonal
        //rectrangle will have width min of these two and at this pint (i,j) we will have 
        //total = +min(x,y);
        for(int i = 0; i < rows; i++){
            for(int k = 0; k < cols; k++){
                int minCnt = INT_MAX;
                for(int l = i; l < rows; l++){
                    minCnt = min(minCnt, tracker[l][k]);
                    total += minCnt;
                }
            }
        }
        return total;
    }
};

/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        if(numRows == 0) return 0;
        int numCols = matrix[0].size();
        int SquareCnt = 0;
        
        //separately processing first ro and olumn
        for(int i = 0; i < numCols; i++){
            if( matrix[0][i] == 1){
                SquareCnt++;
            }
        }
        
        for(int i = 0; i < numRows; i++){
            if( matrix[i][0] == 1){
                SquareCnt++;
            }
        }
        
        //as it counted twice
        if(matrix[0][0] > 0) SquareCnt--;
        
        int len;
        for(int i = 1; i < numRows; i++){
            for(int j = 1; j < numCols; j++){
                if(matrix[i][j] > 0){
                    SquareCnt++;
                }
                if(matrix[i][j] > 0 && matrix[i-1][j-1] > 0){
                    int range = 1;
                    len = sqrt(matrix[i-1][j-1]);
                    for(int k = 1; k <= len; k++){
                        if(matrix[i-k][j] <= 0){
                            break;
                        }
                        
                        if(matrix[i][j-k] <= 0){
                            break;
                        }
                        
                        range++;
                    }
                    
                    matrix[i][j] = range*range;
                    SquareCnt += (range - 1);
                }
            }
        }
        
        return SquareCnt;
    }
};

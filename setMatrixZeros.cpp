/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
concept taken from : https://www.youtube.com/watch?v=6_KMkeh5kEc
                     https://www.youtube.com/watch?v=1KnLIAvTxjQ
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols;
        bool isFirstRowZero = false;
        if(rows > 0){
            cols = matrix[0].size();
        }
        
        for(int i = 0; i < cols; i++){
            if(matrix[0][i] == 0){
                isFirstRowZero = true;
                break;
            }
        }
        
        for(int i = 0; i < cols; i++){
            for(int j = 0; j < rows; j++){
                if(matrix[j][i] == 0){
                    matrix[0][i] = 0;
                    break;
                }
            }
        }
        
        bool rowZero = false;
        for(int i = 1; i < rows; i++){
            rowZero = false;
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    rowZero = true;
                    break;
                }
            }
            
            for(int j = 0; j < cols; j++){
                if(rowZero || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(isFirstRowZero){
            for(int i = 0; i < cols; i++){
                matrix[0][i] = 0;
            }
        }
    }
};
/**********************************Alternate Solution *********************************/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols;
        bool isFirstRowZero = false;
        bool isFirstColZero = false;
        if(rows > 0){
            cols = matrix[0].size();
        }
        
        for(int i = 0; i < cols; i++){
            if(matrix[0][i] == 0){
                isFirstRowZero = true;
                break;
            }
        }
        
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0){
                isFirstColZero = true;
                break;
            }
        }
        
        for(int i = 0; i < cols; i++){
            for(int j = 0; j < rows; j++){
                if(matrix[j][i] == 0){
                    matrix[0][i] = 0;
                    break;
                }
            }
        }
        
        if(isFirstRowZero){
            matrix[0][0] = 0;
        }
        for(int i = 1; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    break;
                }
            }
        }
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(isFirstRowZero){
            for(int i = 0; i < cols; i++){
                matrix[0][i] = 0;
            }
        }
        
        if(isFirstColZero){
            for(int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }
        }
    }
};

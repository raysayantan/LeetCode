/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
 

Constraints:

rows == matrix.length
cols == matrix.length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        if(cols == 0)
            return 0;
        
        int maxArea = 0;
        //Traverse row by row and calculate the length of consecutive one left to the
        //current cell, if current cell is 1.
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(c > 0){
                    if(matrix[r][c] == '1'){
                        matrix[r][c] = ((matrix[r][c - 1] - '0') + 1) + '0';
                    }
                }
                
                //Traverse the matrix and for non-zero cells, try to calculate the maximum area till now
                //and it is calculated based on the following formula: suppose we have two row i and j, 
                //for column c we get min value ammong the rows between matrix[i][c] and matrix[j][c] and
                //let say this is width. and are will be width(j - i + 1);
                if(matrix[r][c] != '0'){
                    int area = 0;
                    int width = INT_MAX;
                    for(int idx = r; idx >= 0; idx--){
                        if(matrix[idx][c] == '0')
                            break;
                    
                        width = min(width, matrix[idx][c] - '0');
                        area = width * (r - idx + 1);
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }
        return maxArea;
    }
};

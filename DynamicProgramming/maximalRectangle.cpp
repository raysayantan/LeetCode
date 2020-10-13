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
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(c == 0){
                    matrix[r][c] = matrix[r][c];
                } else {
                
                    if(matrix[r][c] == '1'){
                        matrix[r][c] = ((matrix[r][c - 1] - '0') + 1) + '0';
                    } else {
                        matrix[r][c] = '0';
                    }
                }
            }
        }
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
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

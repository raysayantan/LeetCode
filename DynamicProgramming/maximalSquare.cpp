/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int numRow = matrix.size();
        if(numRow == 0) return 0;
        int numCol = matrix[0].size();
        
        vector<vector<int>> square(numRow, vector<int>(numCol, 0));
        
        int maxSquare = 0;
        for(int i = 0; i < numCol; i++){
            square[0][i] = matrix[0][i] - '0';
            if(maxSquare == 0 && matrix[0][i] - '0' >= 1){
                maxSquare = 1;
            }
        }
        
        for(int i = 0; i < numRow; i++){
            square[i][0] = matrix[i][0] - '0';
            if(maxSquare == 0 && matrix[i][0] - '0' >= 1){
                maxSquare = 1;
            }
        }
    
        for(int i = 1; i < numRow; i++){
            for(int j = 1; j < numCol; j++){
                square[i][j] = matrix[i][j] - '0';
                if(maxSquare == 0 && square[i][j] > 0){
                    maxSquare = square[i][j];
                }
                if((matrix[i][j] - '0' > 0) && (square[i-1][j-1] > 0)){
                    int count = 1;
                    int len = sqrt(square[i-1][j-1]);
                    for(int k = 1; k <= len; k++){
                        if(square[i-k][j] < 1){
                            break;
                        }
                        if(square[i][j-k] < 1){
                            break;
                        }
                        count++;
                    }
                    square[i][j] = (count)*(count);
                    if(maxSquare < square[i][j]){
                        maxSquare = square[i][j];
                    }
                }
            }
        }
        
        return maxSquare;
    }
};

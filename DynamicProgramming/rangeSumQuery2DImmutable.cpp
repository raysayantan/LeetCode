/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/
class NumMatrix {
    //We will have a extra storage of MxN size, where each row the column i
    //will store the sum from column 0 to column ith element of that row.
    vector<vector<int>> rowSum;
    int rows;
    int cols;
    
    void calcRowSum(vector<int> s, vector<int> &t){
        int sum = 0;
        for(int colIdx = 0; colIdx < s.size(); colIdx++){
            sum += s[colIdx];
            t[colIdx] = sum;
        }
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if(rows > 0){
            cols = matrix[0].size();
        } else {
            cols = 0;
        }
        
        //allocating the memory for the temporary matrix storing the row sum
        //and compute the row sum for each row. For col i in a row r, will have 
        //value stored is the sum of all the values from (r,0) to (r,i)
        rowSum.resize(rows);
        for(int rowIdx = 0; rowIdx < rows; rowIdx++){
            rowSum[rowIdx].resize(cols, 0);
            calcRowSum(matrix[rowIdx], rowSum[rowIdx]);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = 0;
        for(int r = row1; r <= row2; r++){
            //get the row sum till col2
            total += rowSum[r][col2];
            //subtract the first (col1 - 1) columns values if (col1 - 1) >= 0
            if(col1 - 1 >= 0){
                total -= rowSum[r][col1 - 1];
            }
        }
        
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

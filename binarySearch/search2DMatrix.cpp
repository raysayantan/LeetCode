/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if( rows == 0)
            return false;
        int cols = matrix[0].size();
        if(cols == 0)
            return false;
        
        if(target < matrix[0][0] || target > matrix[rows - 1][cols - 1])
            return false;
        
        //find the row where the target might be, i.e. where target is
        // >= first row element and <= the last element, will do the binary
        //search in that row to find that element
        int row = 0;
        for(int i = 0; i < rows; i++){
            if(target <= matrix[i][cols - 1])
                break;
            row++;
        }
        if(row < rows){
            int low = 0;
            int high = cols - 1;
            while(low <= high){
                int mid = (low + high)/2;
                if(target == matrix[row][mid])
                    return true;
                if(target < matrix[row][mid]){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};

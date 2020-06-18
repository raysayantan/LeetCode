/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rowBoundary(2);
        vector<int> colBoundary(2);
        vector<int> result;
        int rows = matrix.size();
        if(rows == 0) 
            return result; 
        int cols = matrix[0].size();
        //update row boundary
        rowBoundary[0] = 0;
        rowBoundary[1] = rows - 1;
        //update column boundary
        colBoundary[0] = 0;
        colBoundary[1] = cols - 1;
        
        int i = 0;
        int k = 0;
        bool rowTraverse = true;
        bool colTraverse = false;
        //move between the boundary row wise and then coulmwise
        //First will start from row 0 and col 0
        while(true){
            if(rowTraverse){
                if(k == colBoundary[0]){
                    //We are at the coloumn lower boundary 
                    //and need to increment till upper one
                    while(k <= colBoundary[1]){
                        result.push_back(matrix[i][k]);
                        k++;
                    }
                    //As we exceed the columnsize by one decrement it
                    k--;
                } else {
                    //Last traversal left us at column at upper 
                    //boundary and will decrement it now till lower one
                    while(k >= colBoundary[0]){
                        result.push_back(matrix[i][k]);
                        k--;
                    }
                    //We moved till lower boundary - 1 so need to increamet it
                    k++;
                }
                //update row boundary and next row to visit
                //The row just now we completed based on that we 
                //have to increment or decrement the boundary
                if(i == rowBoundary[0]){ 
                    rowBoundary[0]++;
                    i = rowBoundary[0];
                }else{
                    rowBoundary[1]--;
                    i = rowBoundary[1];
                }
                if(colBoundary[0] <= colBoundary[1])
                    colTraverse = true;
                rowTraverse = false;
            } else if(colTraverse){
                if(i == rowBoundary[0]){
                    while(i <= rowBoundary[1]){
                        result.push_back(matrix[i][k]);
                        i++;
                    }
                    i--;
                } else {
                    while( i >= rowBoundary[0]){
                        result.push_back(matrix[i][k]);
                        i--;
                    }
                    i++;
                }
                //update column and next column to start visiting
                //The column just now we completed based on that we 
                //have to increment or decrement the boundary
                if(k == colBoundary[0]){
                    colBoundary[0]++;
                    k = colBoundary[0];
                } else {
                    colBoundary[1]--;
                    k = colBoundary[1];
                }
                if(rowBoundary[0] <= rowBoundary[1]){
                    rowTraverse = true;
                }   
                colTraverse = false;
            } else {
                //no more element to traverse so break;
                break;
            }
        }
        
        return result;
    }
};

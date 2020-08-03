/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //We will start for (0,0) and move rowwise till last coloumn
        //then in alternative fashion once columnwise and then rowwise.
        //First move we will go from 0 to n - 1, then 2 consecutive move
        //one column wise and one row wise with n - 2 count and then n - 3
        //and so on till n = 1;
        
        vector<vector<int>> matrix(n, vector(n, 0));
        int counter = 1;
        int loopCnt = n;
        //This will signify if we will move along the row or not
        bool isRowMovement = true;
        int row = 0;
        int col = 0;
        //this will enable decrementing the loop count
        bool done = false;
        //This will hlp to detect when should increment or decremet row and column index
        bool up = true;
        while(loopCnt > 0){
            if(loopCnt == n){
                //Very first row
                isRowMovement = false;
                for(int i = 0; i < loopCnt; i++){
                    matrix[row][col + i] = counter++;
                }
                col = col + loopCnt - 1;
                row++;
                done = true;
            } else {
                //other than first row
                if(isRowMovement){
                    //When we are moving along the row
                    isRowMovement = false;
                    done = true;
                    for(int i = 0; i < loopCnt; i++){
                        if(up){
                           //moving up to the column index
                           matrix[row][col + i] = counter++;
                        } else {
                            //moving down in column index
                            matrix[row][col - i] = counter++;
                        }
                    }
                    
                    //Adjusting row and column after every row walk
                    if(up){
                        row++;
                        col = col + loopCnt - 1;
                    } else {
                        row--;
                        col = col - (loopCnt - 1);
                    }
                } else {
                    //Movinh along the column
                    isRowMovement = true;
                    for(int i = 0; i < loopCnt; i++){
                        if(up){
                            //Moving on increasing row index
                            matrix[row + i][col] = counter++;
                        } else {
                            //Moving alone decreasing row index
                            matrix[row - i][col] = counter++;
                        }
                    }
                    
                    //Adjust row and col after column walk
                    if(up){
                        col--;
                        row = row + loopCnt - 1;
                    } else {
                        col++;
                        row = row - (loopCnt - 1);
                    }
                    up ^= 1;;
                }
            }
            
            //Decrementing loop count after every pair of walk one row and one column
            if(done){
                loopCnt--;
                done = false;
            }
        }
        
        return matrix;
    }
};

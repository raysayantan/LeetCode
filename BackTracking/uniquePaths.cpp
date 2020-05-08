/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.
Accepted
*/
class Solution {
    int uniquePathUtil(int m, int n, vector<vector<int>> &counter){
        if(m < 0 || n < 0) return 0;
        if(m == 0 && n == 0) return 1;
        int top = 0;
        int left = 0;
        if(m-1 >= 0){
            if(counter[m-1][n] > 0){
                top = counter[m-1][n];
            } else {
                top = uniquePathUtil(m-1, n, counter);
            }
        }
        
        if(n-1 >= 0){
            if(counter[m][n-1] > 0){
                left = counter[m][n-1];
            } else {
                left = uniquePathUtil(m, n-1, counter);
            }
        }
        
        counter[m][n] = top + left;
        return top + left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<int> temp(n);
        vector<vector<int>> counter(m, temp);
        return uniquePathUtil(m-1, n-1, counter);
    }
};

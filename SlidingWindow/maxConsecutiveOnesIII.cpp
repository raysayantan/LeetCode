/*
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest (contiguous) subarray that contains only 1s. 
Example 1:
Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation: 
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
Example 2:
Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation: 
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
Note:
1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1 
*/
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int len = A.size();
        int start = 0;
        int end = 0;
        int count = 0;
        int maxCount = 0;
        
        //we have start and end indices which are start and end of the window. if we have
        //'0' at current index, we will check if K > 0 if so increament the counter and decrement 
        //K by one, else we have to increament start by one. While increamenting start, if the 
        //current start is '0' increment K by one and then increment start and also decrement count
        //by one. Everytime we will check if the present count greater than maxCount, id so
        //then assign count to maxCount
        while(end < len){
            if(A[end] == 0){
                if(K > 0){
                    K--;
                    count++;
                    end++;
                } else {
                    if(A[start] == 0){
                        K++;
                    }
                    start++;
                    count--;
                }
            } else {
                count++;
                end++;
            }
            
            if(count > maxCount){
                maxCount = count;
            }
        }
        
        return maxCount;
    }
};

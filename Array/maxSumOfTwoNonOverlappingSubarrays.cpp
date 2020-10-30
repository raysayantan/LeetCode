/*
Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  
(For clarification, the L-length subarray could occur before or after the M-length subarray.)
Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:
0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 
Example 1:
Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
Example 2:
Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
Example 3:
Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] with length 3.
 
Note:
L >= 1
M >= 1
L + M <= A.length <= 1000
0 <= A[i] <= 1000
*/
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int len = A.size();
        int sum = 0;
        for(int idx = 0; idx < len; idx++){
            sum += A[idx];
            A[idx] = sum;
        }
        
        int maxSum = INT_MIN;
        sum = 0;
        for(int idx = L - 1; idx < len; idx++){
            int s1 = A[idx] - ((idx - L >= 0) ? A[idx - L] : 0);
            int s2 = INT_MIN;
            //calculate maximum s2 for a given s1
            //on left side
            if(idx - L >= M - 1){
                for(int i = M - 1; i <= idx - L; i++){
                    s2 = max(s2, A[i] - ((i - M >= 0) ? A[i - M] : 0));
                }
            }
            
            //right side
            if(idx + M <= len - 1){
                for(int i = idx + M; i < len; i++){
                    s2 = max(s2, A[i] - A[i - M]);
                }
            }
            
            maxSum = max(maxSum, s1 + s2);
        }
        
        return maxSum;
    }
};

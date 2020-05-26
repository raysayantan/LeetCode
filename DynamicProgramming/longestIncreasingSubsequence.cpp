/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        if(l == 0 || l == 1) return l;
        int maxLen = 1;
        vector<int> lenArr(l, 1);
        
        for(int i = 1; i < l; i++){
            int cnt = 1;
            for(int k = 0; k < i; k++){
                if(nums[k] < nums[i]){
                    if(lenArr[k] + 1 > lenArr[i]){
                        lenArr[i] = lenArr[k] + 1;
                        if(lenArr[i] > maxLen) maxLen = lenArr[i];
                    }
                }
            }
        }
        
        return maxLen;
    }
};

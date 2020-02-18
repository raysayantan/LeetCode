/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int start = 0, end = len-1;
        
        for(int i = len - 1; i >= 0; i--){
            if(nums[i] == 0){
                start = i;
                for(int j = start; j < end; j++){
                    nums[j] = nums[j+1];
                }
                nums[end] = 0;
                end--;
            }
        }
    }
};

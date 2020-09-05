/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
 

Constraints:

You may assume that the array does not change.
There are many calls to sumRange function.
0 <= nums.length <= 10^4
-10^5 <= nums[i] <= 10^5
0 <= i <= j < nums.length
*/
class NumArray {
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        this->nums.resize(nums.size());
        for(int idx = 0; idx < nums.size(); idx++){
            sum += nums[idx];
            this->nums[idx] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        int startSum = 0;
        int endSum = 0;
        if(i > 0){
            startSum = nums[i - 1];
        }
        
        endSum = nums[j];
        
        return (endSum - startSum);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

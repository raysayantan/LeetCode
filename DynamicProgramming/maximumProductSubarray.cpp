/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        int currProd = 1;
        int prevProdIncl = 1;
        int prevProdExcl = 1;
        int maxProd = INT_MIN;
        bool firstNegReached = false;   
        bool all_less_0_non_consecutive = true;
        for(int i = 0; i < len; i++){
            if((i > 0 && nums[i] < 0 && nums[i-1] < 0) || nums[i] > 0){
               all_less_0_non_consecutive = false; 
            }
            if(maxProd < nums[i]) maxProd = nums[i];
        }
        if(all_less_0_non_consecutive) return maxProd;
        
        maxProd = 1;
        for(int i = 0; i < len; i++){
            if(nums[i] == 0){
                currProd = 1;
                prevProdIncl = 1;
                prevProdExcl = 1;
                firstNegReached = false;
                continue;
            }
            
            currProd *= nums[i];
            prevProdIncl *= nums[i];
            if(firstNegReached == true){
                prevProdExcl *= nums[i];
            }
            if(nums[i] < 0){
                firstNegReached = true;
                if(prevProdIncl > 0){
                    currProd = prevProdIncl;
                } else if(prevProdExcl > 0){
                    currProd = prevProdExcl;
                }
            }
            
            if(currProd > maxProd){
                maxProd = currProd;
            }
        }
        
        return maxProd;
    }
};

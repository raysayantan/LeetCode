/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if( len == 0)
            return 0;
        if(target < nums[0])
            return 0;
        if(target > nums[len - 1])
            return len;
        int low = 0;
        int high = len - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[mid] > target){
                if(mid > 0 && nums[mid - 1] < target){
                    return mid;
                }
                
                high = mid - 1;
            } else {
                if(mid + 1 < len && nums[mid + 1] > target){
                    return mid + 1;
                }
                
                low = mid + 1;
            }
        }
        
        return 0;
    }
};

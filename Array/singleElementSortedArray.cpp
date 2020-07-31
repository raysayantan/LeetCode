/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. 
Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int low = 0;
        int high = len - 1;
        if(len == 1)
            return nums[0];
        
        while(low <= high){
            //we will use the concept of index of the ending duplicate number, ie if
            //a duplicate number ending at odd index then all the numbers till now are in pair
            //else we have a non duplicate element to the left of the current index
            int mid = low + (high - low)/2;
            if(low == high)
                return nums[mid];
            if(mid % 2 == 0){
                if(mid + 1 < len && nums[mid] == nums[mid + 1]){
                    //We are here means all the elements till mid + 1
                    //are in pair so we need to search right of mid + 1
                    low = mid + 2;
                } else if(mid > 0 && nums[mid] == nums[mid - 1]){
                    //need to move left of mid
                    high = mid - 2;
                    
                } else {
                    return nums[mid];
                }
            } else {
                if(mid > 0 && nums[mid] == nums[mid - 1]){
                    //we have all in pair till index mid so move right
                    low = mid + 1;
                } else if(mid + 1 < len && nums[mid] == nums[mid + 1]){
                    //element at left side if mid
                    high = mid - 1;
                }
            }
        }
        
        return - 1;
    }
};

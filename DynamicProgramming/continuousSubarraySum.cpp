/*
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a 
multiple of k, that is, sums up to n*k where n is also an integer.
Example 1:

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:

Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
 

Constraints:

The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> remainderSum;
        
        //we will traverse the vector of integers and calculate the sum till
        //current index and calculate the modulo of the sum with respect to value k.
        //and if this is a new some we will store that in the map using that current index
        //as soon as we will get a sum value same as already existing one then we have the
        //result, because if we have sum till inde i is rem and at index j which is later 
        //than i is (rem + n*k) then we have a sum multiplied by k between element i + 1
        //till jth index.
        int sum = 0;
        remainderSum[0] = -1;
        for(int idx = 0; idx < len; idx++){
            sum += nums[idx];
            if(k != 0)
                sum = sum % k;
            if(remainderSum.find(sum) != remainderSum.end()){
                if(idx - remainderSum[sum] > 1)
                    return true;
            } else {
                remainderSum[sum] = idx;
            }
        }
        
        return false;
    }
};

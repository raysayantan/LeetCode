/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
Example 1:
Input:nums = [1,1,1], k = 2
Output: 2 
Constraints:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //having a unordered map to store the sum frequency
        unordered_map<int, int> sumFreq;
        int currSum = 0;
        int total = 0;
        sumFreq[currSum]++;
        for(int idx= 0; idx < nums.size(); idx++){
            currSum += nums[idx];
            //When we have a sum at current index, if we have (currSum - k)
            //in the map, we will add that frequency to our total outcome
            if(sumFreq.find(currSum - k) != sumFreq.end()){
                total += sumFreq[currSum - k];
            }
            sumFreq[currSum]++;
        }
        
        return total;
    }
};

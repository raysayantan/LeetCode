/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>strg(target+1,0);
        strg[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i>=nums[j]){
                    strg[i]+=strg[i-nums[j]];
                }
            }
        }
        return strg[target];
    }
};

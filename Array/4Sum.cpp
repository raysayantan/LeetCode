/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.
Note:
The solution set must not contain duplicate quadruplets.
Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int l = nums.size();
        vector<vector<int>> result;
        if(l < 4)
            return result;
        
        //sort the array in ascending order
        sort(nums.begin(), nums.end());
        //loop till 4th last element in the array as we need 4 element sum
        for(int i = 0; i < l - 3; i++){
            //as we need unique combination so skipping the same value
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            //already we have one element, so loop untill 3rd last element
            for(int k = i + 1; k < l - 2; k++){
                if(k > i + 1 && nums[k] == nums[k-1])
                    continue;
                int start = k + 1;
                int end = l - 1;
                //we have fiest and second element
                int first = nums[i];
                int second = nums[k];
                int rem = target - (first + second);
                int sum;
                while(start < end){
                    sum = nums[start] + nums[end];
                    if(sum == rem){
                        result.push_back({first, second, nums[start], nums[end]});
                        while(start < end && nums[start] == nums[start + 1]) start++;
                        while(start < end && nums[end] == nums[end - 1]) end--;
                        start++;
                        end--;
                        continue;
                    }
                    
                    if(sum < rem){
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }
        return result;
    }
};

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int l = 0;
        int r = 0;
        int x = 0;
        
        for(int i = 0; i < n; i++){
            l = i+1;
            r = n-1;
            x = nums[i];
            vector<int> v;
            while(l < r){
                int sum = x + nums[l] + nums[r];
                
                if(sum == 0){
                    v.push_back(x);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    s.insert(v);
                    v.clear();
                    l++;
                    r--;
                } else if(sum < 0){
                    l++;
                } else if(sum > 0){
                    r--;
                }
            }
        }
        res.assign(s.begin(), s.end());
        return res;
    }
};

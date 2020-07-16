/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> res;
        for(int i = 0; i < k; i++){
            m[nums[i]]++;
        }
        int maxVal = (m.rbegin())->first;
        res.push_back(maxVal);
        for(int i = 1; i <= nums.size() - k; i++){
            m[nums[i - 1]]--;
            if(m[nums[i - 1]] == 0)
                m.erase(nums[i - 1]);
            m[nums[i + k - 1]]++;
            auto it = m.rbegin();
            while(it->second <= 0){
                it--;
            }
            maxVal = it->first;
            res.push_back(maxVal);
        }
        
        return res;
    }
};

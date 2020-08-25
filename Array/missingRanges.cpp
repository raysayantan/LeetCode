/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int len = nums.size();
        if(len == 0){
            if(lower == upper){
                result.push_back(to_string(lower));
            } else {
                result.push_back(to_string(lower) + "->" + to_string(upper));
            }
            return result;
        }
        
        long l = lower;
        long u = upper;
        int i = 0;
        while(i < len && l < u){
            if(nums[i] >= l){
                if(nums[i] == l){
                    l = (long)(nums[i]) + 1;
                } else if(nums[i] > l){
                    if(nums[i] == l + 1){
                        result.push_back(to_string(l));
                        if(l + 1 == u){
                            l = (long)(nums[i]) + 1;
                            break;
                        }                        
                    } else {
                        if(nums[i] - 1 <= u){
                            result.push_back(to_string(l) + "->" + to_string(nums[i] - 1));
                        } else {
                           result.push_back(to_string(l) + "->" + to_string(u)); 
                        }
                    }
                    
                    l = (long)(nums[i]) + 1;
                }
            }
            i++;
        }
        if(l < u){
            result.push_back(to_string(l) + "->" + to_string(u));
        } else if(nums[len - 1] < l && l == u){
            result.push_back(to_string(l));
        }
        
        return result;
    }
};

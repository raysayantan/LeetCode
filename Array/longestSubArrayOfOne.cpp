/*
Given a binary array nums, you should delete one element from it. Return the size of the longest non-empty subarray containing only 1's in the resulting array.
Return 0 if there is no such subarray.
Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
Example 4:
Input: nums = [1,1,0,0,1,1,1,0,1]
Output: 4
Example 5:
Input: nums = [0,0,0]
Output: 0
Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int range = 0;
        int l = nums.size();
        int iStart = -1;
        int hasZero = 0;
        bool nonZero = false;
        int prevZero = -1;
        int i = 0;
        bool anyZero = false;
        while(i < l){
            if(nonZero == false && nums[i] == 0){
                anyZero = true;
                i++;
                continue;
            }
            //first non-zero occured
            nonZero = true;
            if(iStart == -1){
                //very first 1 in a fresh sequence
                iStart = i;
                i++;
            } else {
                if(nums[i] == 0){
                    anyZero = true;
                    //zero
                    if(hasZero == 0){
                        if(i < l - 1 && nums[i+1] != 0){
                            hasZero = 1;
                            prevZero = i;
                        } else {
                            range = max(range, i - iStart);
                            iStart = -1;
                            nonZero = false;
                            i = i + 2;
                            continue;
                        }
                    } else {
                        range = max(range, i - iStart - hasZero);
                        iStart = prevZero + 1;
                        prevZero = i;
                    }
                    cout<<"Range "<<range<<endl;
                }
                i++;
            }
        }
        if(iStart != -1){
            if(anyZero)
                range = max(range, i - iStart - hasZero);
            else
                range = max(range, i - iStart - 1);
        }
        return range;
    }
};

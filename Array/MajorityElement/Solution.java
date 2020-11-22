/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
*/
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        /*
        We have to pick the lements from the array having occurances more than (len of the array)/3 times.
        Here if we observe then we could find that, there can be atmost two elements that hav this opprtunity.
        let say the length is n so n/3 + n/3 = 2n/3 i.e. with these two elements we have more than 2n/3 times,
        so remaining elements count will be less than n/3. I will be using Majority Element principal to 
        solve the problem.
        */
        int count1 = 0;
        int count2 = 0;
        int element1 = Integer.MIN_VALUE;
        int element2 = Integer.MIN_VALUE;
        //Now if we carefully observed if some elements have count more will be standout, here let
        //say element1 and element2. Let say, if we have element1, element2 and some other element
        //every occurance of some other element will cancel out one i.e. decremented by one. So at 
        //the end, if we have elements count > n/3 it will stand out
        for(int idx = 0; idx < nums.length; idx++){
            if(element1 == nums[idx]){
                count1++;
            } else if(element2 == nums[idx]){
                count2++;
            } else if(element1 == Integer.MIN_VALUE){
                element1 = nums[idx];
                count1++;
            } else if(element2 == Integer.MIN_VALUE){
                element2 = nums[idx];
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        
        //now we have two possible candidates, and need to check there occurances more than len/3
        count1 = 0;
        count2 = 0;
        for(int idx = 0; idx < nums.length; idx++){
            if(nums[idx] == element1) count1++;
            if(nums[idx] == element2) count2++;
        }
        
        List<Integer> result = new ArrayList<>();
        if(count1 > nums.length/3){
            result.add(element1);
        }
        if(count2 > nums.length/3){
            result.add(element2);
        }
        
        return result;
    }
}

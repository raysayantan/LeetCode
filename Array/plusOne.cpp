/*
Given a non-empty array of digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int len = digits.size();
        if(digits[len - 1] < 9){
            digits[len - 1] += 1; 
            return digits;
        } else {
            result.push_back(0);
            int carry = 1;
            int sum = 0;
            int rem = 0;
            int idx = 1;
            for(int i = len - 2; i >= 0; i--){
                sum = digits[i] + carry;
                rem = sum % 10;
                carry = sum / 10;
                result.push_back(rem);
            }
            
            if(carry > 0){
                result.push_back(carry);
            }
            
            reverse(result.begin(), result.end());
            return result;
        }
    }
};

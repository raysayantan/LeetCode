/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if(x < 0){
            negative = true;
        }
        if(x == INT_MAX || x == INT_MIN){
            return 0;
        }
        int num = abs(x);
        int result = 0;
        while(num){
            int rem = num % 10;
            num = num / 10;
            if(negative){
                if(INT_MIN / 10 > (-1)* result || (INT_MIN / 10 == result && rem > (-1)*(INT_MIN % 10))){
                    return 0;
                }
            } else {
                if(INT_MAX / 10 < result || (INT_MAX / 10 == result && rem > INT_MAX % 10)){
                    return 0;
                }
            }
            
            result = result * 10 + rem;
        }
        
        return (negative) ? (-1) * result : result;
    }
};

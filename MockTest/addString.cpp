/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        
        //base conditions
        if(num1.length() == 0 && num2.length() == 0)
            return result;
        if(num1.length() == 0)
            return num2;
        if(num2.length() == 0)
            return num1;
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int sum = 0;
        int carry = 0;
        int rem = 0;
        int l1 = 0;
        int l2 = 0;
        while(l1 < num1.length() && l2 < num2.length()){
            int val1 = num1[l1] - '0';
            int val2 = num2[l2] - '0';
            sum = val1 + val2 + carry;
            rem = sum % 10;
            carry = sum / 10;
            result += to_string(rem);
            l1++;
            l2++;
        }
        
        while(l1 < num1.length()){
            int val1 = num1[l1] - '0';
            sum = val1 + carry;
            rem = sum % 10;
            carry = sum / 10;
            result += to_string(rem);
            l1++;
        }
        
        while(l2 < num2.length()){
            int val2 = num2[l2] - '0';
            sum = val2 + carry;
            rem = sum % 10;
            carry = sum / 10;
            result += to_string(rem);
            l2++;
        }
        
        if(carry > 0){
            result += to_string(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

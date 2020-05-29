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
        string summation = "";
        if(num1 == "") return num2;
        if(num2 == "") return num1;
        int l1 = num1.length();
        int l2 = num2.length();
        int i = l1 - 1;
        int k = l2 - 1;
        int carry = 0;
        int sum = 0;
        while(i >= 0 && k >= 0){
            sum = (num1[i] - '0') + (num2[k] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            summation = to_string(sum) + summation;
            i--;
            k--;
        }
        
        while(i >= 0){
            sum = (num1[i] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            summation = to_string(sum) + summation;
            i--;
        }
        
        while(k >= 0){
            sum = (num2[k] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            summation = to_string(sum) + summation;
            k--;
        }
        
        if(carry > 0){
            summation = to_string(carry) + summation;
        }
        
        return summation;
    }
};

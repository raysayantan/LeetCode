/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
    string sumOfstrings(string s1, string s2){
        string summation = "";
        if(s1 == "") return s2;
        if(s2 == "") return s1;
        int l1 = s1.length();
        int l2 = s2.length();
        int i = l1 - 1;
        int k = l2 - 1;
        int carry = 0;
        int sum = 0;
        while(i >= 0 && k >= 0){
            sum = (s1[i] - '0') + (s2[k] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            summation = to_string(sum) + summation;
            i--;
            k--;
        }
        
        while(i >= 0){
            sum = (s1[i] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            summation = to_string(sum) + summation;
            i--;
        }
        
        while(k >= 0){
            sum = (s2[k] - '0') + carry;
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

public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int l1 = num1.length();
        int l2 = num2.length();
        string prev = "";
        string t = "";
        string suffixString ="";
        for(int i = l2 - 1; i >= 0; i--){
            t = "";
            int carry = 0;
            int p;
            for(int k = l1 - 1; k >= 0; k--){
                p = (num2[i] - '0')*(num1[k] - '0') + carry;
                carry = p / 10;
                p = p % 10;
                t = to_string(p) + t;
            }
            
            if(carry > 0){
                t = to_string(carry) + t;
            }
            t += suffixString;
            suffixString += "0";
            if(prev != "")
                prev = sumOfstrings(prev, t);
            else
                prev = t;
        }
        
        return prev;
    }
};

/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
If multiple answers are possible, return any of them.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:
Input: numerator = 2, denominator = 1
Output: "2"
Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(6)"
Example 4:
Input: numerator = 4, denominator = 333
Output: "0.(012)"
Example 5:
Input: numerator = 1, denominator = 5
Output: "0.2"
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result = "";
        if(numerator == 0){
            return "0";
        }
        string sign = ((numerator >= 0) ^ (denominator >= 0)) ? "-" : "";
        result += sign;
        long num = (long)abs(numerator);
        long div = (long)abs(denominator);
        
        result += to_string(num / div);
        num = num % div;
        
        if(num == 0){
            return result;
        }
        
        result += ".";
        unordered_map<int, int> m;
        m.insert({num, result.length()});
        while(num > 0){
            num *= 10;
            result += to_string(num / div);
            num = num % div;
            
            if(m.find(num) != m.end()){
                int pos = m[num];
                result = result.substr(0, pos) + "(" + result.substr(pos) + ")";
                return result;
            }
            
            m.insert({num, result.length()});
        }
        
        return result;
    }
};

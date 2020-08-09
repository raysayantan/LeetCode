/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.length();
        int bLen = b.length();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string result = "";
        int aIdx = 0;
        int bIdx = 0;
        int sum = 0;
        int rem = 0;
        int c = 0;
        while(aIdx < aLen && bIdx < bLen){
            sum = (a[aIdx] - '0') + (b[bIdx] - '0') + c;
            rem = sum % 2;
            c = sum / 2;
            result += to_string(rem); 
            aIdx++;
            bIdx++;
        }
        
        while(aIdx < aLen){
            sum = (a[aIdx] - '0') + c;
            rem = sum % 2;
            c = sum / 2;
            result += to_string(rem); 
            aIdx++;
        }
        
        while(bIdx < bLen){
            sum = (b[bIdx] - '0') + c;
            rem = sum % 2;
            c = sum / 2;
            result += to_string(rem); 
            bIdx++;
        }
        
        if(c > 0){
            result += to_string(c);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};

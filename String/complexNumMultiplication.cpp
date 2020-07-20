/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int aReal = 0, bReal = 0;
        int aImg = 0, bImg = 0;
        
        //find real and imaginary for a and b
        int i = a.find("+");
        aReal = stoi(a.substr(0,i));
        aImg = stoi(a.substr(i + 1, a.length() - 1 - i - 1));
        
        i = b.find("+");
        bReal = stoi(b.substr(0,i));
        bImg = stoi(b.substr(i + 1, b.length() - 1 - i - 1));
        
        int cReal = (aReal * bReal) + (aImg * bImg)*(-1);
        int cImg = (aReal * bImg) + (bReal * aImg);
        
        string res = to_string(cReal) + "+" + to_string(cImg) + "i";
        return res;
    }
};

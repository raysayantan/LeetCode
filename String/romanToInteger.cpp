/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. 
The number twenty seven is written as XXVII, which is XX + V + II. Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
Example 1:
Input: "III"
Output: 3
Example 2:
Input: "IV"
Output: 4
Example 3:
Input: "IX"
Output: 9
Example 4:
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
class Solution {
public:
    int romanToInt(string s) {
        int l = s.length();
        if(l == 0)
            return 0;
        vector<int> symbol(26);
        //Fill the symbol table
        symbol['M' - 'A'] = 1000;
        symbol['D' - 'A'] = 500;
        symbol['C' - 'A'] = 100;
        symbol['L' - 'A'] = 50;
        symbol['X' - 'A'] = 10;
        symbol['V' - 'A'] = 5;
        symbol['I' - 'A'] = 1;
        int total = 0;
        int i = 0;
        while(i < l){
            if(i+1 < l && symbol[s[i+1] - 'A'] > symbol[s[i] - 'A']){
                //If a lower valued symbol is followed by a higher value
                total += (symbol[s[i+1] - 'A'] - symbol[s[i] - 'A']);
                i = i + 2;
            } else {
                //If the higher value symbol followed by a lower value symbol
                total += symbol[s[i] - 'A'];
                i++;
            }
        }
        return total;
    }
};

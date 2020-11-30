/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. 
If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, 
then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        string res = "";
        int remCnt = len;
        int start = 0;
        int end = k;
        while(remCnt >= k){
            //Take first k character
            string part1 = "";
            if(end >= len)
                part1 = s.substr(start);
            else 
                part1 = s.substr(start, k);
            
            reverse(part1.begin(), part1.end());
            res = res + part1;
            remCnt -= k;
            start += k;
            end += k;
            //rem count is less than k
            if(remCnt < k){
                if(remCnt <= 0) {
                    break;
                }
                string part2 = s.substr(start);
                res += part2;
                remCnt = 0;
                break;
            }
            
            string part2 = s.substr(start, k);
            res += part2;
            remCnt -= k;
            start += k;
            end += k;
        }
        
        if(remCnt > 0){
            string part1 = s.substr(start);
            reverse(part1.begin(), part1.end());
            res += part1;
        }
        
        return res;
    }
};

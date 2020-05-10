/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/
class Solution {
    bool isMatchUtil(vector<vector<int>> &matcher, string s, string p, int i, int j){
        bool ret;
        if(i < s.length() && j < p.length() && matcher[i][j] != -1){
            return (matcher[i][j] == 1) ?  true : false;
        }
        if(j == p.length()){
            ret = (i == s.length());
        } else {
            bool isFirstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
        
            //if there is a star it should be preceded by a char or '.'
            if(j+1 < p.length() && p[j+1] == '*'){
                ret = isMatchUtil(matcher, s, p, i, j+2) || (isFirstMatch && isMatchUtil(matcher, s, p, i+1, j));
            } else {
                ret =isFirstMatch && isMatchUtil(matcher, s, p, i+1, j+1);
            }
        }
        matcher[i][j] = (ret) ? 1: 0;
        return ret;
    }
public:
    bool isMatch(string s, string p) {
        vector<int> t(p.length() + 1, -1);
        vector<vector<int>> matcher(s.length() + 1, t);
        return isMatchUtil(matcher, s, p, 0, 0);
    }
};

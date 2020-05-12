/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<char> matcher;
        int len = s.length();
        if(len <= 1) return 0;
        for(int i = 0; i < len; i++){
            if(s[i] == ')'){
                //If we found the current char is ')', then we will check the matching
                // ')' in the vector, matcher; if we found on then we make that vector entry
                // to p. at the end we will count contineous p and max p count will be the result
                int idx = matcher.size() - 1;
                while(true){
                    if(idx < 0){
                        matcher.push_back(s[i]);
                        break;
                    } else {
                        if(matcher[idx] == '('){
                            matcher[idx] = 'p';
                            break;
                        } else if(matcher[idx] == 'p'){
                            idx--;
                        } else if(matcher[idx] == ')'){
                            matcher.push_back(s[i]);
                            break;
                        }
                    }
                }
            } else {
                matcher.push_back(s[i]);
            }
        }
        
        int maxLen = 0;
        int idx = 0;
        int cnt = 0;
        for(idx = 0; idx < matcher.size(); idx++){
            if(matcher[idx] == 'p'){
                cnt++;
            } else {
                if(cnt > maxLen){
                    maxLen = cnt;
                }
                cnt = 0;
            }
        }
        if(cnt > maxLen) maxLen = cnt;
        return maxLen*2;
    }
};

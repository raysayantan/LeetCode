/*
Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
Example 4:

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
 

Constraints:

1 <= s.length <= 10^5
s[i] is one of  '(' , ')' and lowercase English letters.
*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int openCount = 0;
        for(int idx = 0; idx < s.length(); idx++){
            char c = s[idx];
            if(c == ')'){
                if(openCount == 0) continue;
                
                openCount--;
                st.push(c);
            } else {
                st.push(c);
                if(c == '(') openCount++;
            }
        }
        
        string res = "";
        while(!st.empty()){
            char c = st.top();
            st.pop();
            if(c == '('){
                if(openCount > 0){
                    openCount--;
                    continue;
                } else {
                    res += c;
                }
            } else {
                res += c;
            }
        }
        
        int start = 0;
        int end = res.length() - 1;
        while(start <= end){
            char c = res[start];
            res[start] = res[end];
            res[end] = c;
            start++;
            end--;
        }
        return res;
    }
};

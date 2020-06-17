/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int idx = 0; idx < s.length(); idx++){
            if(s[idx] == '(' || s[idx] == '{' || s[idx] == '['){
                st.push(s[idx]);
            } else {
                if(st.empty())
                    return false;
                if(s[idx] == ')' && st.top() != '(')
                    return false;
                else if(s[idx] == '}' && st.top() != '{')
                    return false;
                else if(s[idx] == ']' && st.top() != '[')
                    return false;
                st.pop();
            }
        }
        
        if(st.empty())
            return true;
        else
            return false;
    }
};

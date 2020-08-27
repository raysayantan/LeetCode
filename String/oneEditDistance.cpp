/*
Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from string t if you can:

Insert exactky one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.
 

Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "a", t = ""
Output: true
Example 4:

Input: s = "", t = "A"
Output: true
 

Constraints:

0 <= s.length <= 104
0 <= t.length <= 104
*/
class Solution {
    int slen;
    int tlen;
    bool helper(string s, int si, string t, int ti, bool &done){
        if(si == slen && ti == tlen){
            return done;
        }
        
        if(si < slen && ti < tlen){
            if(s[si] == t[ti]){
                return helper(s, si + 1, t, ti + 1, done);
            } else {
                if(done){
                    return false;
                } else {
                    //Not yet encountered any mismatch of chars
                    done = true;
                    //1st one for replace, 2nd one for add and 3rd one for delete
                    return (
                            helper(s, si + 1, t, ti + 1, done) ||
                            helper(s, si + 1, t, ti, done) ||
                            helper(s, si, t, ti + 1, done)
                           );
                }
            }
        } else {
            if(si < slen){
                if(done){
                    return false;
                } else {
                    done = true;
                    return helper(s, si + 1, t, ti, done);
                }
            } else if(ti < tlen){
                if(done){
                    return false;
                } else {
                    done = true;
                    return helper(s, si, t, ti + 1, done);
                }
            }
        }
        return false;
    }
public:
    bool isOneEditDistance(string s, string t) {
        bool maxChangeDone = false;
        slen = s.length();
        tlen = t.length();
        bool done = false;
        return helper(s, 0, t, 0, done);
    }
};

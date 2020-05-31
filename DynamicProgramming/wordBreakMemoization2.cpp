/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = s.length();
        set<string> s1(wordDict.begin(), wordDict.end());
        vector<bool> dp(l + 1, false);
        dp[0] = true;
        for(int len = 1; len <= l; len++){
            for(int idx = 0; idx < len; idx++){
                if(dp[idx] && s1.find(s.substr(idx, len - idx)) != s1.end()){
                    dp[len] = true;
                    break;
                }
            }
        }
        return dp[l];
    }
};

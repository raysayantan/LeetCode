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
    bool wordBreakUtil(unordered_map<string, bool> &dictionary, string s, unordered_map<string, bool> &matcher){
        if(s == "") return true;
        if(matcher.find(s) != matcher.end()) return matcher[s];
        for(int i = 1; i <= s.length(); i++){
            if(dictionary.find(s.substr(0, i)) != dictionary.end()){
                bool ret = wordBreakUtil(dictionary, s.substr(i), matcher);
                if(ret == true) {
                    matcher.insert({s.substr(i), true});
                    return true;
                }
            }
        }
        matcher.insert({s,false});
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dictionary;
        unordered_map<string, bool> matcher;
        for(int i = 0; i < wordDict.size(); i++){
            dictionary.insert({wordDict[i], false});
        }
        
        return wordBreakUtil(dictionary, s, matcher);
    }
};

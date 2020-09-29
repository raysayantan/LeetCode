/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 

Note: You may assume the string contains only lowercase English letters.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counter;
        
        for(int idx = 0; idx < s.length(); idx++){
            counter[s[idx]]++;
        }
        
        for(int idx = 0; idx < s.length(); idx++){
            if(counter[s[idx]] == 1){
                return idx;
            }
        }
        
        return -1;
    }
};

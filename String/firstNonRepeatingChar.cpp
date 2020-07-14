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
        int cnt[26];
        int l = s.length();
        int minCnt = -1;
        for(int i =0; i < 26; i++){
            cnt[i] = -1;
        }
        
        for(int i = 0; i < l ; i++){
            if(cnt[int(s[i] - 'a')] == -1){
                cnt[int(s[i] - 'a')] = i;
            }
            else if(cnt[int(s[i] - 'a')] >= 0 )
               cnt[s[i] - 'a'] = -2; 
        }
        
        for(int i =0; i < 26; i++){
            if(cnt[i] >= 0){
                if(minCnt == -1 || minCnt > cnt[i])
                    minCnt = cnt[i];
            }
        }
        
        return minCnt;
    }
};

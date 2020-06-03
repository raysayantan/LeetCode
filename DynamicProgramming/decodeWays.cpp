/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
class Solution {
    int numDecodeUtil(string s, map<string, int>& decodeCounter){
        if(s == "") return 1;
        if(s[0] == '0') return 0;
        if(decodeCounter.find(s) != decodeCounter.end()){
            return decodeCounter[s];
        }
        int total = 0;
        if(s[0] <= '2'){
            if(s.length() > 1){
                if(s[1] != '0'){
                    if((s[0] == '2' && s[1] <= '6') || (s[0] == '1' && s[1] <= '9')){
                        total += numDecodeUtil(s.substr(1), decodeCounter);
                        total += numDecodeUtil(s.substr(2), decodeCounter);
                    } else {
                        total += numDecodeUtil(s.substr(1), decodeCounter);
                    }
                } else {
                    total += numDecodeUtil(s.substr(2), decodeCounter);   
                }
            } else {
                total += numDecodeUtil(s.substr(1), decodeCounter);
            }
        } else {
           total += numDecodeUtil(s.substr(1), decodeCounter); 
        }
        
        decodeCounter.insert({s, total});
        return total;
    }
public:
    int numDecodings(string s) {
        map<string, int> decodeCounter;
        return numDecodeUtil(s, decodeCounter);
    }
};

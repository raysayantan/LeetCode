/*
You have a list of words and a pattern, and you want to know which words in words matches the pattern. A word matches the pattern if there exists a permutation 
of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word. (Recall that a permutation of letters is a 
bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
Return a list of the words in words that match the given pattern. 
You may return the answer in any order.
Example 1:
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 
Note:
1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
*/
class Solution {
    bool match(string word, string pattern){
        unordered_map<char, char> m;
        for(int idx = 0; idx < word.length(); idx++){
            char c = word[idx];
            char p = pattern[idx];
            if(m.find(p) == m.end()){
                m[p] = c;
            } else {
                if(m[p] != c){
                    return false;
                }
            }
        }
        
        vector<bool> seen(26, false);
        for(auto it = m.begin(); it != m.end(); it++){
            if(seen[it->second - 'a']){
                return false;
            }
            
            seen[it->second - 'a'] = true;
        }        
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        int len = words.size();
        for(int idx = 0; idx < len; idx++){
            if(match(words[idx], pattern)){
                result.push_back(words[idx]);
            }
        }
        
        return result;
    }
};

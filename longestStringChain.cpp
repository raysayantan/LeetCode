/*
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
 

Note:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.
*/
class Solution {
    vector<vector<int>> edges;
    vector<int> pathLength;
    int largestPath(int v){
        if(pathLength[v] > 0){
            return pathLength[v];
        }
        
        pathLength[v] = 1;
        for(auto it = edges[v].begin(); it != edges[v].end(); it++){
            pathLength[v] = max(pathLength[v], largestPath(*it) + 1);
        }
        
        return pathLength[v];
    }
public:
    int longestStrChain(vector<string>& words) {
        int len = words.size();
        unordered_map<string, int> m1(len);
        edges.resize(len);
        pathLength.resize(len);
        for(int i = 0; i < len; i++){
            m1[words[i]] = i;
        }
        
        for(int i = 0; i < len; i++){
            string s = words[i];
            for(int j = 0; j < s.length(); j++){
                string temp = s.substr(0, j) + s.substr(j+1);
                auto it = m1.find(temp);
                if(it != m1.end()){
                    edges[it->second].push_back(i);
                }
            }
        }
        
        int result = 0;
        for(int i = 0; i < len; i++){
            result = max(result, largestPath(i));
        }
        return result;        
    }
};

/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, 
where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, set<char>> dictionary;
        unordered_map<char, int> indegree;
        int len = words.size();
        string result = "";
        
        //Initialize the inorder and dictionary map
        for(int i = 0; i < len; i++){
            for(int k = 0; k < words[i].length(); k++){
                indegree[words[i][k]] = 0;
                dictionary[words[i][k]] = {};
            }
        }
        
        //populate the indegree and adjuscency list
        for(int i = 0; i < len - 1; i++){
            //check for later one is the prefix of the earlier
            if(words[i].length() > words[i + 1].length() && words[i].find(words[i + 1]) == 0){
                return "";
            }
            
            for(int k = 0; k < min(words[i].length(), words[i + 1].length()); k++){
                if(words[i][k] != words[i + 1][k]){
                    if(dictionary[words[i][k]].find(words[i + 1][k]) == dictionary[words[i][k]].end()){
                        dictionary[words[i][k]].insert(words[i + 1][k]);
                        indegree[words[i + 1][k]]++;
                    }
                    break;
                }
            }
        }
        
        //queue used for BFS
        queue<char> q;
        for(auto it = indegree.begin(); it != indegree.end(); it++){
            //push all the nodes having '0' indegree
            if(it->second == 0){
                q.push(it->first);
            }
        }
        
        while(!q.empty()){
            char c = q.front();
            q.pop();
            result += c;
            //Decrement the indegree of all the adjucent node of the current character node
            for(auto it = dictionary[c].begin(); it != dictionary[c].end(); it++){
                indegree[*it]--;
                if(indegree[*it] == 0){
                    q.push(*it);
                }
            }
        }
        
        //now check all the character are in the result else return empty string
        if(result.length() < indegree.size()){
            return "";
        }
        
        return result;
    }
};

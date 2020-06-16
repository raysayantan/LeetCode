/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> container;
        int len = strs.size();
        for(int i = 0; i < len; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(container.find(s) == container.end()){
                vector<int> v;
                v.push_back(i);
                container.insert({s, v});
            } else {
                auto v = container[s];
                v.push_back(i);
                container[s] = v;
            }
        }
        
        vector<vector<string>> result;
        for(auto it = container.begin(); it != container.end(); it++){
            auto v = it->second;
            vector<string> str;
            for(int i = 0; i < v.size(); i++){
                str.push_back(strs[v[i]]);
            }
            result.push_back(str);
        }
        
        return result;
    }
};

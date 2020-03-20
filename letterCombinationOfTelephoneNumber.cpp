/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    void createDictionary(map<int, vector<string>> &dict){
        vector<string> v{"a","b","c"};
        dict.insert({2,v});
        v = {"d","e","f"};
        dict.insert({3,v});
        v = {"g","h","i"};
        dict.insert({4,v});
        v = {"j","k","l"};
        dict.insert({5,v});
        v = {"m","n","o"};
        dict.insert({6,v});
        v = {"p","q","r","s"};
        dict.insert({7,v});
        v = {"t","u","v"};
        dict.insert({8,v});
        v = {"w","x","y","z"};
        dict.insert({9,v});
    }
    
   
    void createComination(string digits, int idx, int len, vector<string> &result, map<int, vector<string>> &dict, string &res){
        if(idx == len){
            result.push_back(res);
            return;
        }
        
        vector<string> v = dict[(digits[idx] - '0')];
        for(int i = 0; i < v.size(); i++){
            string temp = res;
            res += v[i]; 
            createComination(digits, idx+1, len, result, dict, res);
            res = temp;
        }
        
    }
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if(len == 0) return {};
        map<int,vector<string>> dict;
        string res;
        res = "";
        vector<string> result;
        createDictionary(dict);
        vector<string> v = dict[2];
        createComination(digits, 0, len, result, dict, res);
        return result;
    }
};

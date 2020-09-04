/*
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  
For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.
You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
Accepted
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        //Will take a map of <char, pair<int, int>>; here key is the character
        //and value is the pair of number, first one is the min count and 
        //second one is the current count. Every time we completed the scanning
        //a string will check each value in the pair; first one will be the minimum 
        //of these two and if the second one is 0, we will have that count always zero
        //for both first and second of the pair.
        unordered_map<char, pair<int, int>> counter;
        
        //first traverse the first string and populate these two array
        for(int cIdx = 0; cIdx < A[0].length(); cIdx++){
            char c = A[0][cIdx];
            int first = counter[c].first + 1;
            pair<int, int> value = make_pair(first, 0);
            counter[c] = value;
        }
        
        
        //now rest of the string and for counter take the least value
        for(int strIdx = 1; strIdx < A.size(); strIdx++){
            string currStr = A[strIdx];
            for(int cIdx = 0; cIdx < currStr.length(); cIdx++){
                char c = currStr[cIdx];
                auto it = counter.find(c);
                if(it != counter.end()){
                    pair<int, int> value = it->second;
                    int first = value.first;
                    int second = value.second + 1;
                    counter[c] = make_pair(first, second);
                    //update the present count of the character
                    counter[c] = make_pair(first, second);
                }
            }
            
            //now loop through the map and assign the min in the first place of the counter pair
            for(auto it = counter.begin(); it != counter.end(); it++){
                char key = it->first;
                pair<int, int> value = it->second;
                int minval = min(value.first, value.second);
                value = make_pair(minval, 0);
                counter[key] = value;
            }
        }
        
        //Now we have the final map with the updated counter
        vector<string> result;
        for(auto it = counter.begin(); it != counter.end(); it++){
            pair<int, int> value = it->second;
            char key = it->first;
            if(value.first > 0){
                string t = "";
                t += key;
                for(int cnt = 0; cnt < value.first; cnt++)
                    result.push_back(t);
            }
        }
        
        return result;
    }
};

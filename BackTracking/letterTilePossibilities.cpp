/*
You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: tiles = "AAABBC"
Output: 188
Example 3:

Input: tiles = "V"
Output: 1
 

Constraints:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.
*/
class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> counter(26, 0);
        for(int idx = 0; idx < tiles.length(); idx++){
            counter[tiles[idx] - 'A']++;
        }
        
        return dfs(counter);
    }
    
    int dfs(vector<int> &counter){
        int total = 0;
        
        for(int idx = 0; idx < 26; idx++){
            if(counter[idx] > 0){
                total++;
                counter[idx]--;
                total += dfs(counter);
                counter[idx]++;
            }
        }
        
        return total;
    }
};

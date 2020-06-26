/*
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, 
and return a list of integers representing the size of these parts.
Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:
S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int l = S.length();
        int lastIndex;
        char nextChar;
        vector<int> indices(26, -1);
        vector<int> result;
        if(l == 0)
            return result;
        int i = 0;
        //This array will track the last index on the character occurance
        for(int k = l-1; k >= 0; k--){
            indices[S[k] - 'a'] = max(indices[S[k] - 'a'], k);
        }
        //This will have the last partition end index
        int prev = -1;
        while(i < l){
            nextChar = S[i];
            lastIndex = indices[S[i] - 'a'];
            while(i <= lastIndex){
                //Check for the new char
                if(S[i] != nextChar){
                    nextChar = S[i];
                    //Update the maxium value range we need to look
                    lastIndex = max(lastIndex, indices[S[i] - 'a']);
                }
                i++;
            }
            //Now update the result with the partition
            if(prev != -1){
                result.push_back(i - prev);
                prev = i;
            } else {
                result.push_back(i);
                prev = i;
            }
        }
        return result;
    }
};

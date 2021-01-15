/*
We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

 

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
 

Constraints:

1 <= hours.length <= 10000
0 <= hours[i] <= 16
*/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
         map<int, int> indices;
        int sum = 0;
        int maxlen = 0;
        for(int idx = 0; idx < hours.size(); idx++){
            sum += (hours[idx] > 8) ? 1 : -1;
            if(indices.find(sum) == indices.end()){
                indices.insert({sum, idx});
            }
            
            if(sum > 0){
                maxlen = idx + 1;
            } else {
                if(indices.find(sum - 1) != indices.end()){
                    maxlen = max(maxlen, idx - indices[sum -1]);
                }
            }
        }
        
        return maxlen;
    }
};

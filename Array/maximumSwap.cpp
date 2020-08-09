/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
*/
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> number;
        int rem = 0;
        int maxDigit = INT_MIN;
        //We will keep track of to index, one is the heighest number and
        //other one is higher number from the right
        vector<int> maxIdx(2, -1);
        //We will keep track of to index, one is the lower number and
        //other one is previous lower number than maxDigit from the right
        vector<int> swapIdx(2,-1);
        int currIdx = 0;
        int result = num;
        
        //We will loop through all the digits from the right(Least significant)
        //as soon as we find a higher digit we will kepp track of that in
        //vector maxDigit[0] and previous value of maxDigit[0] will be stored
        //at maxDigit[1] and corresponding swapping position of swapIdx as well
        while(num > 0){
            rem = num % 10;
            num = num / 10;
            number.push_back(rem);
            if(rem > maxDigit && num > 0){
                maxDigit = rem;
                maxIdx[1] = maxIdx[0];
                maxIdx[0] = currIdx;
                swapIdx[1] = swapIdx[0];
                swapIdx[0] = -1;
            } else if(rem < maxDigit && maxIdx[0] != -1){
                swapIdx[0] = currIdx;
            }
            currIdx++;
        }
        
        //If we found a higher digit from right and a smaller digit left of that higher
        //one, we will swap that two position and construc the new number
        if(swapIdx[0] != -1 || swapIdx[1] != -1){
            int i = 1;
            if(swapIdx[0] != -1){
                i = 0;
            }
            int t = number[swapIdx[i]];
            number[swapIdx[i]] = number[maxIdx[i]];
            number[maxIdx[i]] = t;
            
            result = 0;
            for(int idx = number.size() - 1; idx >= 0 ; idx--){
                result = result*10 + number[idx];
            }
        }
        
        return result;
    }
};

/*
Given an array of integers arr of even length n and an integer k.
We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
Return True If you can find a way to do that or False otherwise.
Example 1:
Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
Example 2:

Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).
Example 3:

Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
Example 4:

Input: arr = [-10,10], k = 2
Output: true
Example 5:

Input: arr = [-1,1,-2,2,-3,3,-4,4], k = 3
Output: true
 

Constraints:

arr.length == n
1 <= n <= 10^5
n is even.
-10^9 <= arr[i] <= 10^9
1 <= k <= 10^5
*/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        //As the array already of even length so no need to check that
        int l = arr.size();
        //we will keep the number of occurances of the remainder after
        //diving arr[i] by k in an map of freq
        unordered_map<int,int> freq;
        
        //loop through the elements and store the remainder/module div count
        //we do (arr[i]%k) + k)%k to handle the negative numbers
        for(int i = 0; i < l; i++){
            freq[((arr[i]%k) + k)%k]++;
        }
        
        //using the principal of modulo division, to make a number say, i divisable by k
        // we need to add (k - i%k) with that num, so for each remainder say, x there must
        //a y = k - x, so that suming up these two number will make a pair divisable by k
        //i.e. we nee to have equal number of freq of remainder i%k and (k - i%k). and if 
        //remaider is 0, then it must be even numder to for a pair
        for(int i = 0; i < l; i++){
            int rem = ((arr[i]%k) + k)%k;
            if(rem == 0 && (freq[rem] % 2) != 0){
                return false;
            }
            if(rem != 0 && freq[rem] != freq[k - rem]){
                return false;
            }
        }
        
        return true;
    }
};

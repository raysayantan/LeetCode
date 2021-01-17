/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNum(n, 1);
        int l2 = 0;
        int l3 = 0;
        int l5 = 0;
        for(int idx = 1; idx < n; idx++){
            int ugly = min(min(uglyNum[l2]*2, uglyNum[l3]*3), uglyNum[l5]*5);
            uglyNum[idx] = ugly;
            if(ugly == uglyNum[l2]*2) l2++;
            else if(ugly == uglyNum[l3]*3) l3++;
            else if(ugly == uglyNum[l5]*5) l5++;
        }
        for(int idx = 0; idx < n; idx++){
            cout<<uglyNum[idx]<<endl;
        }
        return uglyNum[n - 1];
    }
};

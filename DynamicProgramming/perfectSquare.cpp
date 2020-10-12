/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
/****************************************First approach*********************************************/
class Solution {
public:
    int numSquares(int n) {
        vector<int> container(n + 1, 0);
        container[0] = 0;
        container[1] = 1;
        if(n < 2){
            return container[n];
        }
        
        for(int num = 2; num <= n; num++){
            int val = sqrt(num);
            int target = val * val;
            if(target == num){
                //perfect square
                container[num] = 1;
            } else {
                int div = num / target;
                int rem = num % target;
                int count = container[target] * div + container[rem];
                
                target = sqrt(target - 1);
                target *= target;
                while(target >= 1){
                    div = num / target;
                    rem = num % target;
                    int curr = container[target] * div + container[rem];
                    count = min(curr, count);
                    target = sqrt(target - 1);
                    target *= target;
                }
                
                container[num] = count;
            }
        }
        
        return container[n];
    }
};

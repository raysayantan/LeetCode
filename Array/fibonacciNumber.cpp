/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

 

Example 1:

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Note:

0 ≤ N ≤ 30.
*/
class Solution {
    map<int, int> container;
    int helper(int N) {
        if(container.find(N) != container.end()){
            return container[N];
        } else {
            int sum1 = 0;
            int sum2 = 0;
            if(container.find(N - 1) != container.end()){
                sum1 = container[N - 1];
            } else {
                sum1 = fib(N - 1);
                container.insert({N - 1, sum1});
            }
            
            if(container.find(N - 2) != container.end()){
                sum2 = container[N - 2];
            } else {
                sum2 = fib(N - 2);
                container.insert({N - 2, sum2});
            }
            
            container.insert({N, sum1 + sum2});
            return container[N];
        }
    }
public:
    int fib(int N) {
        container.insert({0, 0});
        container.insert({1, 1});
        return helper(N);
    }
};

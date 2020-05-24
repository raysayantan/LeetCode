/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
class Solution {
    int climStairUtil(int n, map<int, int> &m){
        if(n == 0) return 1;
        if(n == 1) return 1;
        int c = 0;
        if(m.find(n) != m.end()){
            return m[n];
        } else {
            c = climStairUtil(n - 1, m) + climStairUtil(n-2, m);
        }
        m.insert({n,c});
        cout<<n<<":"<<c<<endl;
        return c;
    }
public:
    int climbStairs(int n) {
        map<int,int> m;
        m.insert({0,1});
        m.insert({1,1});
        int count = climStairUtil(n, m);
        
        return count;
    }
};

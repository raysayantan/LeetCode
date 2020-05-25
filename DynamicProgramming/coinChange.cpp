/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        sort(coins.begin(), coins.end());
        vector<vector<int>> coinCal(coins.size(), vector<int>(amount + 1, INT_MAX));
        for(int i = 0; i < coins.size(); i++){
            coinCal[i][0] = 0;
        }
        for(int j = 1; j <= amount; j++){
            if(j % coins[0] == 0){
                coinCal[0][j] = j / coins[0];
            }
        }
        for(int i = 1; i < coins.size(); i++){
            for(int j = 1; j <= amount; j++){
                if( j >= coins[i]){
                    int temp = INT_MAX;
                    if(coinCal[i][j - coins[i]] != INT_MAX){
                        temp = coinCal[i][j - coins[i]] + 1;
                    }
                    coinCal[i][j] = min(coinCal[i-1][j], temp);
                } else {
                    coinCal[i][j] = coinCal[i-1][j];
                }
            }
        }
        return (coinCal[coins.size() - 1][amount] == INT_MAX)? -1 : coinCal[coins.size() - 1][amount];
    }
};

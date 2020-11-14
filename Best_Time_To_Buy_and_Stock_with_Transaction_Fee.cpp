/*Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.*//





class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int> &prices,int &fee,int k,int index){
        if(index == prices.size()) return 0;
        if(dp[index][k] != -1) return dp[index][k];
        int temp = 0;
        if(k == 1){
            temp = dfs(prices,fee,0,index + 1) - prices[index] - fee;
            temp = max(temp,dfs(prices,fee,1,index + 1));
        } else {
            temp = dfs(prices,fee,1,index + 1) + prices[index];
            temp = max(temp,dfs(prices,fee,0,index + 1));
        }
        return dp[index][k] = temp;
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int> (2,-1));
        return dfs(prices,fee,1,0);
    }
};

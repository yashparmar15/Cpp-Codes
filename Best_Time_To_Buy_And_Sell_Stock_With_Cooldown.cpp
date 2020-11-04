/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]*/



class Solution {
public:
    int ans = 0;
    // 2 - buy
    // 1 - sell
    int dfs(vector<int> &prices,int k,int index,vector<vector<int>> &dp){
        if(index >= prices.size()) return 0;
        if(dp[index][k - 1] != -1) return dp[index][k - 1];
        int sum = 0;
        if(k == 2){
            int buy = dfs(prices,1,index + 1,dp) - prices[index];
            int nobuy = dfs(prices,2,index + 1,dp);
            sum = max(buy,nobuy);
        } else {
            int sell = dfs(prices,2,index + 2,dp) + prices[index];
            int nosell = dfs(prices,1,index + 1,dp);
            sum = max(sell,nosell);
        }
        return dp[index][k - 1] = sum;
    }
    int maxProfit(vector<int>& prices) {
        int k = 2;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        for(int i = 0 ; i < prices.size() ; i++){
            ans = max(ans,dfs(prices,k,i,dp));
        }
        return ans;
    }
};

/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
Example 4:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105*/


class Solution {
public:
    int ans = 0;
    int dfs(vector<int> &prices,int k,int index,vector<vector<vector<int>>> &dp,int left){
        if(index >= prices.size() or left == 0) return 0;
        if(dp[index][k - 1][left - 1] != -1) return dp[index][k - 1][left - 1];
        int sum = 0;
        if(k == 2){
            int buy = dfs(prices,1,index + 1,dp,left) - prices[index];
            int nobuy = dfs(prices,2,index + 1,dp,left);
            sum = max(buy,nobuy);
        } else {
            int sell = dfs(prices,2,index + 1,dp,left - 1) + prices[index];
            int nosell = dfs(prices,1,index + 1,dp,left);
            sum = max(sell,nosell);
        }
        return dp[index][k - 1][left - 1] = sum;
    }
    int maxProfit(vector<int>& prices) {
        int k = 2;
        if(prices.size() < 2) return 0;
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        ans = max(ans,dfs(prices,k,0,dp,2));
        return ans;
    }
};

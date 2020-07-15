/* Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.*/

class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        for(int i = 1 ; i <= n ; i++){
            int mini = n;
            for(int j = 1 ; j <= int(sqrt(n)) + 1 ; j++){
                if(i - j*j >= 0){
                    mini = min(mini,dp[i - j*j] + 1);
                }
            }
            dp[i] = mini;
        }
        return dp[n];
    }
};

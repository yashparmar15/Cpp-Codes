/*You are given a rows x cols matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (rows - 1, cols - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative return -1.

Notice that the modulo is performed after getting the maximum product.

 

Example 1:

Input: grid = [[-1,-2,-3],
               [-2,-3,-3],
               [-3,-3,-2]]
Output: -1
Explanation: It's not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
Example 2:

Input: grid = [[1,-2,1],
               [1,-2,1],
               [3,-4,1]]
Output: 8
Explanation: Maximum non-negative product is in bold (1 * 1 * -2 * -4 * 1 = 8).
Example 3:

Input: grid = [[1, 3],
               [0,-4]]
Output: 0
Explanation: Maximum non-negative product is in bold (1 * 0 * -4 = 0).
Example 4:

Input: grid = [[ 1, 4,4,0],
               [-2, 0,0,1],
               [ 1,-1,1,1]]
Output: 2
Explanation: Maximum non-negative product is in bold (1 * -2 * 1 * -1 * 1 * 1 = 2).
 

Constraints:

1 <= rows, cols <= 15
-4 <= grid[i][j] <= 4*/


class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<long long int,long long int>>> dp(n,vector<pair<long long int,long long int>> (m));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                dp[i][j].first = INT_MIN;
                dp[i][j].second = INT_MAX;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                dp[i][0].first = grid[0][0];
                dp[i][0].second = grid[0][0];
            } else {
                dp[i][0].first = dp[i - 1][0].first * grid[i][0];
                dp[i][0].second = dp[i - 1][0].first * grid[i][0];
            }
        }
        for(int i = 0 ; i < m ; i++){
            if(i == 0){
                dp[0][i].first = grid[0][0];
                dp[0][i].second = grid[0][0];
            } else {
                dp[0][i].first = dp[0][i - 1].first * grid[0][i];
                dp[0][i].second = dp[0][i - 1].first * grid[0][i];
            }
        }
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                long long int x = grid[i][j] * max(dp[i][j-1].first,dp[i-1][j].first);
                long long int y = grid[i][j] * min(dp[i][j-1].second,dp[i-1][j].second);
                dp[i][j].first = max(x,y);             
                dp[i][j].second = min(x,y);
            }
        }
        long long int ans = dp[n - 1][m - 1].first;
        if(ans < 0) return -1;
        return ans % 1000000007;
    }
};

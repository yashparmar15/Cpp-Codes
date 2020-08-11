/*You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colours: Red, Yellow or Green while making sure that no two adjacent cells have the same colour (i.e no two cells that share vertical or horizontal sides have the same colour).

You are given n the number of rows of the grid.

Return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown:

Example 2:

Input: n = 2
Output: 54
Example 3:

Input: n = 3
Output: 246
Example 4:

Input: n = 7
Output: 106494
Example 5:

Input: n = 5000
Output: 30228214
 

Constraints:

n == grid.length
grid[i].length == 3
1 <= n <= 5000*/

class Solution {
public:
    int M = 1000000007;
    long long int numOfWays(int n) {
        //ABC,ACB,BAC,BCA,CAB,CBA
        //BCA,B
        //CAB
        //BAB
        //BCB
        
        
        //ABA,BAB,CAC,CBC,BCB,ABA
        //CAB
        //BAB
        //BCB
        //CAC
        //BAC
        
        long long int dp[n][2];
        dp[0][0] = 6;
        dp[0][1] = 6;
        for(int i = 1 ; i < n ; i++){
            dp[i][0] = ((2*dp[i - 1][0]%M)%M + (2*dp[i - 1][1]%M)%M) % M;
            dp[i][1] = ((2*dp[i - 1][0]%M)%M + ((3%M)*(dp[i - 1][1])%M)%M) % M;
        }
        return (dp[n - 1][0]%M + dp[n - 1][1]%M)%M;
    }
};

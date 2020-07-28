/*You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

 

Example 1:

Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.
Example 2:

Input: d = 2, f = 6, target = 7
Output: 6
Explanation: 
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: d = 2, f = 5, target = 10
Output: 1
Explanation: 
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
Example 4:

Input: d = 1, f = 2, target = 3
Output: 0
Explanation: 
You throw one die with 2 faces.  There is no way to get a sum of 3.
Example 5:

Input: d = 30, f = 30, target = 500
Output: 222616187
Explanation: 
The answer must be returned modulo 10^9 + 7.
 

Constraints:

1 <= d, f <= 30
1 <= target <= 1000*/


class Solution {
public:
    int M = 1000000007;
    int numRollsToTarget(int d, int f, int target) {
        //     1   2   3   4   5   6   7   8   9   10
        // 1   1   1   1   1   1   1   0   0   0   0   
        // 2   0   1   2   3   4   5   6   5   4   3
        // 3   0   0   1   3   6   10  15  21  25  27
        int dp[d + 1][target + 1];
        memset(dp,0,sizeof(dp));
        for(int i = 1 ; i <= d ; i++){
            for(int j = 1 ; j <= target ; j++){
                if(i == 1){
                    if(j <= f)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 0;
                }else{
                    int s = 0;
                    int k = j - 1;
                    int x = 0;
                    while(x < f and k >= 1){
                        s = (s%M + dp[i - 1][k]%M)%M;
                        x++;
                        k--;
                    } 
                    dp[i][j] = s%M;
                }
            }
        }
        return dp[d][target]%M;
    }
};

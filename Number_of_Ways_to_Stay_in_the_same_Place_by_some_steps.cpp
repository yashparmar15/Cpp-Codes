/*You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array or stay in the same place  (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer still at index 0 after exactly steps steps.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
Example 2:

Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
Example 3:

Input: steps = 4, arrLen = 2
Output: 8
 

Constraints:

1 <= steps <= 500
1 <= arrLen <= 10^6*/


class Solution {
public:
    int M = 1000000007;
    int stay;
    vector<vector<long long int>> dp;
    long long int dfs(int steps,int arrLen){
        if(arrLen > stay or steps < 0 or arrLen <= 0) return 0;
        if(arrLen == stay and steps == 0) return 1;
        if(steps == 0) return 0;
        if(dp[steps][arrLen] != -1) return dp[steps][arrLen];
        dp[steps][arrLen] = (dfs(steps - 1,arrLen)%M + dfs(steps - 1,arrLen + 1)%M + dfs(steps - 1,arrLen - 1)%M)%M;
        return dp[steps][arrLen];
    }
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen,steps / 2 + 1);
        stay = arrLen;
        dp.resize(steps + 1,vector<long long> (arrLen + 1,-1));
        return (dfs(steps - 1,arrLen - 1)%M + dfs(steps - 1,arrLen)%M + dfs(steps - 1,arrLen + 1)%M)%M;
    }
};

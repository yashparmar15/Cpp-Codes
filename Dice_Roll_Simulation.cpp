/*A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times. 

Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.

Two sequences are considered different if at least one element differs from each other. Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 2, rollMax = [1,1,2,2,2,3]
Output: 34
Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.
Example 2:

Input: n = 2, rollMax = [1,1,1,1,1,1]
Output: 30
Example 3:

Input: n = 3, rollMax = [1,1,1,2,2,3]
Output: 181
 

Constraints:

1 <= n <= 5000
rollMax.length == 6
1 <= rollMax[i] <= 15*/


class Solution {
public:
    int dp[5001][6][16];
    int M = 1000000007;
    long long int dfs(int n,vector<int> &arr,int index,int prev){
        if(n == 0) return 1;
        if(dp[n][index][prev] != -1) return dp[n][index][prev];
        long long int sum = 0;
        for(int i = 0 ; i < 6 ; i++){
            if(index == i) {
                if(prev < arr[i])           
                    sum += dfs(n - 1,arr,index,prev + 1);
            } else {
                sum += dfs(n - 1,arr,i,1);
            }
        }
        return dp[n][index][prev] = sum % M;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return dfs(n,rollMax,0,0) % M;
    }
};

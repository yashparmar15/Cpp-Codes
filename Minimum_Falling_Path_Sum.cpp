/*Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

 

Constraints:

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> dp;
        for(int i = 0 ; i < A.size() ; i++){
            vector<int> temp(A[0].size(),INT_MAX);
            dp.push_back(temp);
        }
        for(int i = 0 ; i < A[0].size() ; i++){
            dp[0][i] = A[0][i];
        }
        for(int i = 1 ; i < A.size() ; i++){
            for(int j = 0 ; j < A[0].size() ; j++){
                if(j == 0){
                    if(j + 1 < A[0].size())
                        dp[i][j] = min(dp[i - 1][j],dp[i - 1][j + 1]);
                    else
                        dp[i][j] = dp[i - 1][j];
                } else {
                    if(j == A[0].size() - 1){
                        dp[i][j] = min(dp[i - 1][j],dp[i - 1][j - 1]);
                    } else {
                        dp[i][j] = min(dp[i - 1][j],min(dp[i - 1][j - 1],dp[i - 1][j + 1]));
                    }
                }
                dp[i][j] += A[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < A[0].size() ; i++){
            ans = min(ans,dp[dp.size() - 1][i]);
        }
        return ans;
    }
};

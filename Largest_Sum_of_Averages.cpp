/*We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input: 
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation: 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 

Note:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
Answers within 10^-6 of the correct answer will be accepted as correct.*/


class Solution {
public:
    vector<vector<double>> dp;
    double ans = 0;
    double dfs(vector<int> &A,int k,int index){
        if(index == A.size())
            return 0;
        if(dp[index][k] != -1) return dp[index][k];
        double flag = 0;
        if(k == 1){
            for(int i = index ; i < A.size() ; i++)
                flag += A[i];
            return flag / (A.size() - index);
        }
        double sum = 0,res = 0;
        for(int i = index ; i < A.size() ; i++){
            sum += A[i];
            flag = sum / (i - index + 1) + dfs(A,k - 1,i + 1);
            res = max(res,flag);
        }
        return dp[index][k] = res;
        
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        dp.resize(A.size(),vector<double>(K + 1,-1));
        return dfs(A,K,0);
    }
};

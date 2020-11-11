/*Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length*/


class Solution {
public:
    int ans = 0;
    vector<int> dp;
    int dfs(vector<int> &A,int &k,int index){
        if(index == A.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int sum = 0;
        int end = k + index;
        if(end > A.size()) end = A.size();
        int Max = 0;
        for(int i = index ; i < end ; i++){
            Max = max(Max,A[i]);
            sum = max(sum,dfs(A,k,i + 1) + (i - index + 1) * Max);
        }
        return dp[index] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int sum = 0;
        dp.resize(A.size(),-1);
        for(auto a : A) sum += a;
        if(K == 1) return sum;
        return dfs(A,K,0);
    }
};

/*Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

 

Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
Example 2:

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.
Example 3:

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
 

Constraints:

1 <= arr.length <= 10^5
-10^4 <= arr[i] <= 10^4*/


class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int> &arr,int index,int k){
        if(index == arr.size()) return -9899;
        if(dp[index][k] != -1) return dp[index][k];
        int sum = arr[index];
        if(k) sum = max(sum,dfs(arr,index + 1,0));
        sum = max(sum,arr[index] + dfs(arr,index + 1,k));
        return dp[index][k] = sum;

    }
    int maximumSum(vector<int>& arr) {
        dp.resize(arr.size(),vector<int>(2,-1));
        int ans = INT_MIN;
        for(int i = 0 ; i < arr.size() ; i++)
            ans = max(ans,dfs(arr,i,1));
        return ans;
    }
};

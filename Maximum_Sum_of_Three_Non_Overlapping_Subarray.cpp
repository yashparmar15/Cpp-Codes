/*In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:

Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
 

Note:

nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).*/


class Solution {
public:
    vector<int> ans;
    vector<vector<int>> dp;
    void dfs2(vector<int> &nums,int &k,int s,int index){
        if(s == 0) return;
        int temp1 = nums[index] + dfs(nums,k,s - 1,index + k);
        int temp2 = dfs(nums,k,s,index + 1);
        if(temp1 >= temp2){
            ans.push_back(index);
            dfs2(nums,k,s - 1,index + k);
        } else {
            dfs2(nums,k,s,index + 1);
        }
    }
    int dfs(vector<int> &nums,int &k,int s,int index){
        if(s == 0) return 0;
        if(index >= nums.size()) return INT_MIN;
        if(dp[index][s] != -1) return dp[index][s];
        int sum = 0;
        sum = max(sum,dfs(nums,k,s - 1,index + k) + nums[index]);
        sum = max(sum,dfs(nums,k,s,index + 1));
        return dp[index][s] = sum;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int &k) {
        vector<int> v;
        int sum = 0;
        for(int i = 0 ; i < k ; i++)
            sum += nums[i];
        v.push_back(sum);
        for(int i = k ; i < nums.size() ; i++){
            sum = sum - nums[i - k] + nums[i];
            v.push_back(sum);
        }
        dp.resize(v.size(),vector<int>(4,-1));
        dfs(v,k,3,0);
        dfs2(v,k,3,0);
        return ans;
    }
};

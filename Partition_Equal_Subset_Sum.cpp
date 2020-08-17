/*Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11]*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        long int sum=0;
        for(auto i:nums)
            sum+=i;

        if(sum%2)  
            return false;
        else
        {
            int w = sum/2;
            vector<vector<bool> > dp(n+1, vector<bool>(w+1,false)); 

            for(auto i=0;i<n+1;i++)
                dp[i][0] = true;

            for(auto i=1;i<n+1;i++)
                for(auto j=1;j<w+1;j++)
                {
                    if(nums[i-1]<=j)
                        dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j];
                }

        return dp[n][w];
        }
    }
};

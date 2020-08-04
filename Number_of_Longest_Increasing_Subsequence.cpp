/*Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.*/



class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> dp;
        if(nums.size() == 0)
            return 0;
        for(int i = 0 ; i < nums.size() ; i++){
            dp.push_back(make_pair(0,0));
        }
        dp[0] = make_pair(1,1);
        for(int i = 1 ; i < nums.size() ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j])
                    dp[i].first = max(dp[j].first,dp[i].first);
            }
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j] and dp[j].first == dp[i].first)
                    dp[i].second += dp[j].second;
            }
            dp[i].first++;
            if(dp[i].first == 1)
                dp[i].second = 1;
        }
        int ans = 0;
        int m = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            cout << dp[i].first << " " << dp[i].second << endl;
            if(dp[i].first > ans){
                ans = dp[i].first;
                m = dp[i].second;
            }
        }
        int a = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(dp[i].first == ans){
                a = a + dp[i].second;
            }
        }
        return a;
    }
};

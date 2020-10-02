/*You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].*/


class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        vector<int> dp(pairs.size(),0);
        int ans = 0;
        for(int i = 0 ; i < pairs.size() ; i++){
            for(int j = 0 ; j < i ; j++){
                if(pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i],dp[j]);
            }
            dp[i]++;
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

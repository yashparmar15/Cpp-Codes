/*You are given two sorted arrays of distinct integers nums1 and nums2.

A valid path is defined as follows:

Choose array nums1 or nums2 to traverse (from index-0).
Traverse the current array from left to right.
If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
Score is defined as the sum of uniques values in a valid path.

Return the maximum score you can obtain of all possible valid paths.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:



Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
Output: 30
Explanation: Valid paths:
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
The maximum is obtained with the path in green [2,4,6,8,10].
Example 2:

Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
Output: 109
Explanation: Maximum sum is obtained with the path [1,3,5,100].
Example 3:

Input: nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
Output: 40
Explanation: There are no common elements between nums1 and nums2.
Maximum sum is obtained with the path [6,7,8,9,10].
Example 4:

Input: nums1 = [1,4,5,8,9,11,19], nums2 = [2,3,4,11,12]
Output: 61
 

Constraints:

1 <= nums1.length <= 10^5
1 <= nums2.length <= 10^5
1 <= nums1[i], nums2[i] <= 10^7
nums1 and nums2 are strictly increasing.*/


class Solution {
public:
    unordered_map<int,int> M1,M2;
    vector<vector<long long>> dp;
    long long int dfs(int index,vector<int> &nums1,vector<int> &nums2,int flag){
        if(flag and index >= nums1.size()) return 0;
        if(!flag and index >= nums2.size()) return 0;
        if(dp[index][flag]) return dp[index][flag];
        long long int temp = 0;
        if(flag){
            if(M2.find(nums1[index]) != M2.end()) temp = max(temp,dfs(M2[nums1[index]] + 1,nums1,nums2,0) + nums1[index]);
            temp = max(temp,dfs(index + 1,nums1,nums2,flag) + nums1[index]);
        } else {
            if(M1.find(nums2[index]) != M1.end()) temp = max(temp,dfs(M1[nums2[index]] + 1,nums1,nums2,1) + nums2[index]) ;
            temp = max(temp,dfs(index + 1,nums1,nums2,flag) + nums2[index]);
        }
        return dp[index][flag] = temp;
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size();
        if(nums2.size() > M) M = nums2.size();
        dp.resize(M,vector<long long>(2,0));
        for(int i = 0 ; i < nums1.size() ; i++)
            M1[nums1[i]] = i;
        for(int i = 0 ; i < nums2.size() ; i++)
            M2[nums2[i]] = i;
        long long int ans = max(dfs(0,nums1,nums2,1),dfs(0,nums1,nums2,0));
        return ans % 1000000007;
    }
};

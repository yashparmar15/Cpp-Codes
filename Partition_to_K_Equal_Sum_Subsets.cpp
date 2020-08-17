/*Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 

Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.*/


class Solution {
    bool value = false;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        
        if (sum % k != 0) {
            return false;
        }
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<int> val (k, 0);
        helper(val, nums, 0, sum / k);
        return value;
    }
    
    void helper(vector<int>&val, vector<int>& nums, int idx, int bucketSize) {
        if (idx == nums.size()) {
            value = true;
            return;
        }
        
        for(int i = 0; i < val.size(); i++) {
            if (val[i] + nums[idx] > bucketSize || value == true) {
                continue;
            }
            
            val[i] += nums[idx];
            helper(val, nums, idx + 1, bucketSize);
            val[i] -= nums[idx];
            
            if (val[i] == 0) break;
        }
    }
};

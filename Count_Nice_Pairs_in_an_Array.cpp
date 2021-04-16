/*You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
Example 2:

Input: nums = [13,10,35,24,76]
Output: 4
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109*/



class Solution {
public:
    int MOD = 1000000007;
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> M;
        for(int i = 0 ; i < nums.size() ; i++){
            int num1 = nums[i];
            int num2 = 0;
            while(num1 > 0){
                num2 = num2 * 10 + num1 % 10;
                num1 = num1 / 10;
            }
            // cout << num1 << " " << num2 << endl;
            M[nums[i] - num2]++;
        }
        long long int ans = 0;
        for(auto m : M){
            long long int num = m.second;
            // cout << num << " " << m.first << endl;
            ans = (ans % MOD + ((num % MOD) * (num % MOD - 1)) / 2) % MOD;
        }
        return ans % MOD;
    }
};

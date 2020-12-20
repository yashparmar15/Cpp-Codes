/*You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104*/


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int prev[nums.size()];
        memset(prev,-1,sizeof(prev));
        int temp[100000];
        memset(temp,-1,sizeof(temp));
        for(int i = 0 ; i < nums.size() ; i++){
            if(temp[nums[i]] != -1)
                prev[i] = temp[nums[i]];
            temp[nums[i]] = i;
        }
        memset(temp,0,sizeof(temp));
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            temp[i] = sum;
        }
        int ans = 0;
        int pre = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            // cout << prev[i] << " ";
            if(prev[i] == -1){
                if(pre == -1) ans = max(ans,temp[i]);
                else ans = max(ans,temp[i] - temp[pre]);
            } else {
                ans = max(ans,temp[i] - temp[max(pre,prev[i])]);
                pre = max(pre,prev[i]);
            }
        }
        // cout << endl;
        return ans;
    }
};

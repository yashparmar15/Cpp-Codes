/*Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

A subarray is a contiguous subsequence of the array.

Return the length of the shortest subarray to remove.

 

Example 1:

Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].
Example 2:

Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
Example 3:

Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.
Example 4:

Input: arr = [1]
Output: 0
 

Constraints:

1 <= arr.length <= 10^5
0 <= arr[i] <= 10^9*/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int low = 0,high = nums.size() - 1;
        int ans = INT_MAX;
        while(low + 1 < nums.size() and nums[low] <= nums[low + 1])
            low++;
        ans = min(ans,high - low);
        if(ans == 0) return ans;
        while(high >= low and nums[high] >= nums[high - 1])
            high--;
        ans = min(ans,high);
        int i = 0,j = high;
        while(i <= low and j < nums.size()){
            if(nums[i] <= nums[j]){
                ans = min(ans,j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};

/*You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109*/


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> left(n,0),right(n,0);
        left[0] = nums[0];
        for(int i = 1 ; i < n ; i++)
            left[i] += left[i - 1] + nums[i];
        right[n - 1] = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--)
            right[i] += right[i + 1] + nums[i];
        unordered_map<int,int> L,R;
        for(int i = 0 ; i < n ; i++){
            L[left[i]] = i + 1;
            R[right[i]] = n - i;
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(left[i] == x) ans = min(ans,L[left[i]]);
            if(R.find(x - left[i]) != R.end() and R[x - left[i]] + L[left[i]] <= n)
                ans = min(ans,R[x - left[i]] + L[left[i]]);
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            if(right[i] == x) ans = min(ans,R[right[i]]);
            if(L.find(x - right[i]) != L.end() and L[x - right[i]] + R[right[i]] <= n)
                ans = min(ans,L[x - right[i]] + R[right[i]]);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

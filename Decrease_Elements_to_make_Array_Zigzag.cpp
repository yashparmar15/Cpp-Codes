/*Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.

An array A is a zigzag array if either:

Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
Return the minimum number of moves to transform the given array nums into a zigzag array.

 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation: We can decrease 2 to 0 or 3 to 1.
Example 2:

Input: nums = [9,6,1,6,2]
Output: 4
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000*/


class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int res = 0;
        if(nums.size() == 2)
            return abs(nums[1] - nums[0]) + 1;
        for(int i = 1 ; i < nums.size() - 1 ; i += 2){
            int num = nums[i] - min(nums[i - 1],nums[i + 1]) + 1;
            if(num > 0)
                res += num;
        }
        if(nums.size() % 2 == 0){
            int num = nums[nums.size() - 1] - nums[nums.size() - 2] + 1;
            if(num > 0)
                res += num;
        }
        int flag = res;
        cout << flag << endl;
        res = 0;
        for(int i = 2 ; i < nums.size() - 1 ; i += 2){
            int num = nums[i] - min(nums[i - 1],nums[i + 1]) + 1;
            if(num > 0)
                res += num;
        }
        if(nums.size() % 2 == 1){
            int num = nums[nums.size() - 1] - nums[nums.size() - 2] + 1;
            if(num > 0)
                res += num;
        }
        int num = nums[0] - nums[1] + 1;
        if(num > 0) res += num;
        cout << res << endl;
        return min(flag,res);
    }
};

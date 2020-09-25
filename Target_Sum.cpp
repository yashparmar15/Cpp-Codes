/*You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
 

Constraints:

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.*/


class Solution {
public:
    int ans = 0;
    void dfs(vector<int> &nums,int sum,int &S,int index){
        if(sum == S and index == nums.size())
            ans++;
        if(index == nums.size()) return;
        dfs(nums,sum + nums[index],S,index + 1);
        dfs(nums,sum - nums[index],S,index + 1);    
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0) return 0;
        dfs(nums,nums[0],S,1);
        dfs(nums,-nums[0],S,1);
        return ans;
    }
};


/////////////////////////////////////////////////////////

class Solution {
public:
    int ans = 0;
    vector<vector<int>> M;
    int dfs(vector<int> &nums,int sum,int &S,int index){
        if(sum == S and index == nums.size())
            return 1;
        if(index == nums.size()) return 0;
        if(M[index][20000 - sum]) return M[index][20000 - sum];
        M[index][20000 - sum] = dfs(nums,sum + nums[index],S,index + 1) + dfs(nums,sum - nums[index],S,index + 1);  
        return M[index][20000 - sum];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        M.resize(20,vector<int>(40000,0));
        if(nums.size() == 0) return 0;
        ans += dfs(nums,nums[0],S,1);
        ans += dfs(nums,-nums[0],S,1);
        return ans;
    }
};


// class Solution {
// public:
//     int ans = 0;
//     void dfs(vector<int> &nums,int sum,int &S,int index){
//         if(sum == S and index == nums.size())
//             ans++;
//         if(index == nums.size()) return;
//         dfs(nums,sum + nums[index],S,index + 1);
//         dfs(nums,sum - nums[index],S,index + 1);    
//     }
//     int findTargetSumWays(vector<int>& nums, int S) {
//         if(nums.size() == 0) return 0;
//         dfs(nums,nums[0],S,1);
//         dfs(nums,-nums[0],S,1);
//         return ans;
//     }
// };

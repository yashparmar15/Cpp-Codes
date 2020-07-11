// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]




class Solution {
public:
    void recur(vector<int> nums,vector<vector<int>> &ans,vector<int> temp,int index){
        if(temp.size() <= nums.size()){
            ans.push_back(temp);
        }
        if(temp.size() == nums.size())
            return;
        for(int i = index ; i < nums.size() ; i++){
            temp.push_back(nums[i]);
            recur(nums,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(nums,ans,temp,0);
        return ans;
    }
};
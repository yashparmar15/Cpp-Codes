// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]



class Solution {
public:
    void recur(vector<vector<int>> &ans,vector<int> &temp,vector<int> &nums,int index){
        ans.push_back(temp);
        for(int i = index ; i < nums.size() ; i++){
            if(i == index or nums[i] != nums[i - 1]){
                temp.push_back(nums[i]);
                recur(ans,temp,nums,i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        recur(ans,temp,nums,index);
        return ans;
    }
};
// Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.

 

// Example:

// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
 

// Constraints:

// The length of the given array will not exceed 15.
// The range of integer in the given array is [-100,100].
// The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.



class Solution {
public:
    void recur(vector<int> nums,vector<int> temp,set<vector<int>> &ans,int index){
        if(temp.size() >= 2){
            ans.insert(temp);
        }
        if(temp.size() == nums.size())
            return;
        for(int i = index ; i < nums.size() ; i++){
            if(nums[i] != INT_MIN and (temp.size() == 0 or nums[i] >= temp[temp.size() - 1])){
                int t = nums[i];
                temp.push_back(nums[i]);
                nums[i] = INT_MIN;
                recur(nums,temp,ans,i+1);
                temp.pop_back();
                nums[i] = t;
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        recur(nums,temp,ans,0);
        vector<vector<int>> res;
        for(auto t : ans){
            res.push_back(t);
        }
        return res;
    }
};
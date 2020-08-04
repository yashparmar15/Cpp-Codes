/*Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]*/

class Solution {
public:
    void recur(vector<vector<int>> &ans,vector<int> temp , vector<int> nums,unordered_map<int,int> M){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(!M[nums[i]]){
                M[nums[i]] = 1;
                temp.push_back(nums[i]);
                recur(ans,temp,nums,M);
                M[nums[i]] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        unordered_map<int,int> M;
        recur(ans,temp,nums,M);
        return ans;
    }
};

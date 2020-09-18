// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i = 0;i < nums.size() ; i++){
            if(m.count(target - nums[i])){
                res.push_back(i);
                res.push_back(m[target - nums[i]]);
            }
            else{
                m.insert({nums[i],i});
            }
        }
        return res;
    }
};












class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> M;
        for(int i = 0 ; i < nums.size() ; i++)
            M[nums[i]]++;
        vector<int> ans(2,0);
        int flag;
        for(int i = 0 ; i < nums.size() ; i++){
            if(target == 2*nums[i] and M[nums[i]] > 1){
                ans[0] = i;
                flag = nums[i];
                break;
            } else {
                if(M[target - nums[i]] and nums[i] != target - nums[i]){
                    ans[0] = i;
                    flag = target - nums[i];
                    break;
                }
            }
        }
        for(int i = 0 ; i < nums.size() ; i++)
            if(flag == nums[i] and i != ans[0]){
                ans[1] = i;
                break;
            }
        return ans;
    }
};

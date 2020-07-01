// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// Example:

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]


////// solution 1 

class Solution {
public:
    void recur(int i , vector<vector<int>> &sol , vector<int> nums){
        if(i == nums.size()){
            sol.push_back(nums);
            return;
        }
        for(int k = i ; k < nums.size() ; k++){
           if(i != k and nums[k] == nums[i]) continue;
            swap(nums[k],nums[i]);
            recur(i + 1, sol,nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> sol;
        int i = 0;
        recur(i,sol,nums);
        return sol;
    }
};


//solution 2 (Not Efficient)


class Solution {
public:
    void recur(int i , set<vector<int>> &sol , vector<int> nums){
        if(i == nums.size()){
            sol.insert(nums);
            return;
        }
        for(int k = i ; k < nums.size() ; k++){
            for(int j = k ; j < nums.size() ; j++){
                swap(nums[j],nums[k]);
                recur(k + 1,sol,nums);
                swap(nums[j],nums[k]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> sol;
        int i = 0;
        recur(i,sol,nums);
        vector<vector<int>> ans;
        for(auto t : sol){
            ans.push_back(t);
        }
        return ans;
    }
};
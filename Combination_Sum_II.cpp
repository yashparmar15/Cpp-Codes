// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]


// Solution 1 (Efficient)

class Solution {
public:
    void recur(vector<vector<int>> &ans , vector<int> candidates , int target , int cur , vector<int> temp ,int index){
        if(cur == target){
            ans.push_back(temp);
            return;
        }
        if(cur > target)
            return;
        for(int i = index ; i < candidates.size() ; i++){
            if(i and candidates[i] == candidates[i - 1] and i > index) continue;
            cur = cur + candidates[i];
            temp.push_back(candidates[i]);
            recur(ans,candidates,target,cur,temp,i+1);
            cur = cur - candidates[i];
            temp.pop_back();   

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        int cur = 0;
        vector<int> temp;
        recur(ans,candidates,target,cur,temp,0);
        return ans;
    }
};

// Solution 2 (Not that much efficient)


class Solution {
public:
    void recur(set<vector<int>> &ans , vector<int> candidates , int target , int cur , vector<int> temp ,int index){
        if(cur == target){
            ans.insert(temp);
            return;
        }
        if(cur > target)
            return;
        for(int i = index ; i < candidates.size() ; i++){
            cur = cur + candidates[i];
            temp.push_back(candidates[i]);
            recur(ans,candidates,target,cur,temp,i+1);
            cur = cur - candidates[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>> ans;
        int cur = 0;
        vector<int> temp;
        recur(ans,candidates,target,cur,temp,0);
        vector<vector<int>> sol;
        for(auto t : ans){
            sol.push_back(t);
        }
        return sol;
    }
};



// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// Example:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]



class Solution {
public:
    void recur(vector<vector<int>> &ans ,int n, int k, int i, vector<int> temp){
        if(i == k + 1){
            ans.push_back(temp);
            return;
        }
        for(int j = i ; j <= n ; j++){
           if((temp.size() != 0 and temp[temp.size() - 1] < j) or temp.size() == 0){
                temp.push_back(j);
                recur(ans,n,k,i+1,temp);
                temp.pop_back();  
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        int i = 1;
        vector<int> temp;
        recur(ans,n,k,i,temp);
        return ans;
    }
};
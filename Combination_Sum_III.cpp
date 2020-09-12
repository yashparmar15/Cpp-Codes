// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Note:

// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]




class Solution {
public:
    void recur(int n , int k , int index , vector<bool> visited , set<vector<int>> &ans , vector<int> temp,int cur){
        if(temp.size() == k and cur == n){
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        if(temp.size() == k)
            return;
        if(cur >= n)
            return;
        for(int i = index ; i <= 9 ; i++){
            if(!visited[i]){
                visited[i] = true;
                cur = cur + i;
                temp.push_back(i);
                recur(n,k,index + 1,visited,ans,temp,cur);
                visited[i] = false;
                temp.pop_back();
                cur = cur - i;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> ans;
        int index = 1;
        vector<bool> visited(10 , false);
        vector<int> temp;
        int cur = 0;
        recur(n,k,index,visited,ans,temp,cur);
        vector<vector<int>> sol;
        for(auto t : ans)
            sol.push_back(t);
        return sol;
    }
};



///////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    vector<vector<int>> ans;
    void recur(int &k,int &n,vector<int> temp,int sum,int index){
        if(sum > n or temp.size() > k) return;
        if(temp.size() == k and sum == n){
            ans.push_back(temp);
            return;
        }
        for(int i = index ; i <= 9 ; i++){
            temp.push_back(i);
            recur(k,n,temp,sum + i,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        recur(k,n,temp,0,1);
        return ans;
    }
};

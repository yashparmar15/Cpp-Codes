class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(vector<int> &stones,int index,int k){
        if(index == stones.size() - 1) return true;
        if(index >= stones.size()) return false;
        if(dp[index][k] != -1) {
            if(dp[index][k]) return true;
            return false;
        }
        bool temp = false;
        for(int i = index + 1 ; i < stones.size() ; i++){
            if(stones[index] + k == stones[i] and k != 0) temp = temp or dfs(stones,i,k);
            if(stones[index] + k - 1 == stones[i] and k != 0) temp = temp or dfs(stones,i,k - 1);
            if(stones[index] + k + 1 == stones[i]) temp = temp or dfs(stones,i,k + 1);
        }
        if(temp) dp[index][k] = 1;
        else dp[index][k] = 0;
        return temp;
    }
    bool canCross(vector<int>& stones) {
        dp.resize(stones.size(),vector<int>(1000,-1));
        return dfs(stones,0,0);
    }
};

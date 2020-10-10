class Solution {
public:
    int ans = 0;
    vector<vector<int>> dp;
    int dfs(string &s,string &t,string temp,int i,int j){
        if(temp == t) return 1;
        if(i >= s.size() or j >= t.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = dfs(s,t,temp,i + 1,j);
        if(s[i] == t[j])
            dp[i][j] += dfs(s,t,temp + t[j],i + 1,j + 1);
        ans = max(ans,dp[i][j]);
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        dp.resize(s.size(),vector<int>(t.size(),-1));
        dfs(s,t,"",0,0);
        return ans;
    }
};

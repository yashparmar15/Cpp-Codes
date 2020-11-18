int Solution::solve(vector<vector<int> > &A) {
    vector<int> dp(A.size(),1);
    int ans = 1;
    for(int i = 0 ; i < A.size() ; i++){
        for(int j = 0 ; j < i  ; j++){
            if(A[j][1] < A[i][0])
                dp[i] = max(dp[i],dp[j] + 1);
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

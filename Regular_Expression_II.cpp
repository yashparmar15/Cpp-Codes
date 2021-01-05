bool dynamic(const string& A, const string& B, int m, int n, vector<vector<int>>& aux){
        if(m<=0 && n<=0)
            return true;
        if(n<=0)
            return false;
        if(aux[m][n]!=-1)
            return aux[m][n];
        bool ans=false;
        if((m>0 && A[m-1]==B[n-1] )|| B[n-1]=='.'){
            if(m>0)
                ans=dynamic(A, B, m-1, n-1, aux);
        }
        else if(B[n-1]=='*'){
            ans=dynamic(A, B, m, n-2, aux);
            if((m>0 && A[m-1]==B[n-2]) || B[n-2]=='.')
                if(m>0)
                    ans= ans || dynamic(A, B, m-1, n, aux);
        }
        aux[m][n]=ans;
        return ans;
    }

int Solution::isMatch(const string A, const string B) {
    int m=A.size(), n=B.size();
        vector<vector<int>> aux(m+1, vector<int>(n+1, -1));
        return dynamic(A, B, m, n, aux);
}

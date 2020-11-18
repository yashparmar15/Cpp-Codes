int Solution::solve(vector<int> &A, int B) {
    if(B == 1){
        for(int i = 0 ; i < A.size() ; i++)
            if(A[i] == 0) return -1;
        return A.size();
    }
    int ans = 0;
    int last = -1;
    for(int i = 0 ; i < B ; i++){
        if(A[i] == 1)
            last = i;
    }
    if(last == -1) return -1;
    ans = 1;
    int i = last + 1;
    if(last + B - 1 >= A.size() - 1) return ans;
    for( ; i < A.size() ; i++){
        int j = i;
        last = -1;
        while(j < A.size() and j < i + 2 * B - 2){
            if(A[j] == 1)
                last = j;
            j++;
        }
        ans++;
        if(last + B - 1 >= A.size() - 1) return ans;
        if(last == -1) return -1;
        i = last + 1;
    }
    return ans;
}

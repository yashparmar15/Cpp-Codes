int Solution::solve(string A) {
    int start = 0,end = A.size() - 1;
    int count = 0;
    while(start < end){
        if(A[start] != A[end]){
            count++;
            if(A[start + 1] == A[end])
                start++;
            else if(A[end - 1] == A[start])
                end--;
            else
                return false;
        } else {
            start++;
            end--;
        }
    }
    if(count > 1)
        return false;
    return true;
}

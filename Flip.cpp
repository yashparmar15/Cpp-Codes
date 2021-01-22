/*https://www.interviewbit.com/problems/flip/*/



vector<int> Solution::flip(string A) {
    int count = 0;
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] == '1') count++;
    }
    if(count == A.size()) return {};
    int zero = 0,one = 0;
    int start = -1;
    int end = -1;
    int val = 0;
    //  1   1   0   0   0   1   1   0   0   1   0
    //  -1  -2  -1  0   1   0   -1  0   1   0   1
    zero = one = 0;
    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] == '1') continue;
        else {
            zero = 1;
            one = 0;
            i++;
            int maxx = 1;
            int ts = i - 1;
            int te = i - 1;
            int v = 1;
            while(i < A.size() and zero >= one){
                if(A[i] == '1') one++;
                else zero++;
                if(zero - one > v){
                    te = i;
                    v = zero - one;
                }
                i++;
            }
            i--;
            if(v > val){
                val = v;
                start = ts;
                end = te;
            }
        }
    }
    return {start + 1,end + 1};
}

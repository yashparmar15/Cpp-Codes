/*Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0*/


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = 0;
        vector<int> M1;
        map<int,int> M2;
        int N = A.size();
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                M1.push_back(A[i] + B[j]);
            }
        }
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(M2.count(C[i] + D[j])){
                    M2[C[i] + D[j]] ++;
                }
                else{
                    M2[C[i] + D[j]] = 1;
                }
            }
        }
        for(int i = 0 ; i < N*N ; i++){
            if(M2.count(-M1[i])){
                ans = ans + M2[-M1[i]];
            }
        }
        return ans;
    }
};

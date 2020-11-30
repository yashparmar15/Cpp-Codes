/*Given an array A of non-negative integers, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful.  Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].

 

Example 1:

Input: [1,17,8]
Output: 2
Explanation: 
[1,8,17] and [17,8,1] are the valid permutations.
Example 2:

Input: [2,2,2]
Output: 1
 

Note:

1 <= A.length <= 12
0 <= A[i] <= 1e9*/



class Solution {
public:
    int ans = 0;
    void backtrack(vector<int> &A,int prev,int index){
        if(index == A.size()){
            ans++;
            return;
        }
        for(int i = 0 ; i < A.size() ; i++){
            if(i + 1 < A.size() and A[i] == A[i + 1]) continue;
            if(prev == -1) {
                int t = A[i];
                A[i] = -1;
                prev = t;
                backtrack(A,prev,index + 1);
                prev = -1;
                A[i] = t;
            } else {
                if(A[i] != -1){
                    int num = prev + A[i];
                    int sq = sqrt(num);
                    if(sq * sq == num){
                        int t = A[i],t1 = prev;
                        A[i] = -1;
                        prev = t;
                        backtrack(A,prev,index + 1);
                        prev = t1;
                        A[i] = t;
                    }
                }
            }
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(),A.end());
        backtrack(A,-1,0);
        return ans;
    }
};

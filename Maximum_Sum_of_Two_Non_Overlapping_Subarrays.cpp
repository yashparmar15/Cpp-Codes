/*Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  (For clarification, the L-length subarray could occur before or after the M-length subarray.)

Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:

0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 

Example 1:

Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
Example 2:

Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
Example 3:

Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] with length 3.
 

Note:

L >= 1
M >= 1
L + M <= A.length <= 1000
0 <= A[i] <= 1000*/


class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> v1(A.size(),-1),v2(A.size(),-1);
        int s = 0;
        for(int i = 0 ; i < L ; i++)
            s += A[i];
        v1[0] = s;
        for(int i = 1 ; i <= A.size() - L ; i++){
            s = s - A[i - 1] + A[i + L - 1];
            v1[i] = s;
        }
        s = 0;
        for(int i = 0 ; i < M ; i++)
            s += A[i];
        v2[0] = s;
        for(int i = 1 ; i <= A.size() - M ; i++){
            s = s - A[i - 1] + A[i + M - 1];
            v2[i] = s;
        }
        int ans = 0;
        for(int i = 0 ; i < A.size() ; i++){
            for(int j = i + L ; j < A.size() ; j++){
                ans = max(ans,v1[i] + v2[j]);
            }
        }
        for(int i = 0 ; i < A.size() ; i++){
            for(int j = i + M ; j < A.size() ; j++){
                ans = max(ans,v1[j] + v2[i]);
            }
        }
        return ans;
    }
};



//////////////////////// O(N) ///////////////////////


class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> v1(A.size(),-1),v2(A.size(),-1);
        int s = 0;
        for(int i = 0 ; i < L ; i++)
            s += A[i];
        v1[0] = s;
        for(int i = 1 ; i <= A.size() - L ; i++){
            s = s - A[i - 1] + A[i + L - 1];
            v1[i] = s;
        }
        s = 0;
        for(int i = 0 ; i < M ; i++)
            s += A[i];
        v2[0] = s;
        for(int i = 1 ; i <= A.size() - M ; i++){
            s = s - A[i - 1] + A[i + M - 1];
            v2[i] = s;
        }
        int max1 = -1,max2 = -1;
        vector<int> v3(A.size(),-1),v4(A.size(),-1);
        for(int i = v1.size() - 1 ; i >= 0 ; i--){
            max1 = max(max1,v1[i]);
            max2 = max(max2,v2[i]);
            v3[i] = max1;
            v4[i] = max2;
        }
        int ans = 0;
        for(int i = 0 ; i < A.size() - M ; i++){
            ans = max(ans,v2[i] + v3[i + M]);
        }
        for(int i = 0 ; i < A.size() - L ; i++){
            ans = max(ans,v1[i] + v4[i + L]);
        }
        return ans;
    }
};

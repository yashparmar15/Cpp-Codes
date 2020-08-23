/*We are given an array A of positive integers, and two positive integers L and R (L <= R).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.

Example :
Input: 
A = [2, 1, 4, 3]
L = 2
R = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Note:

L, R  and A[i] will be an integer in the range [0, 10^9].
The length of A will be in the range of [1, 50000].*/


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans = 0;
        int index = -1;
        int left = 0;
        int count = 0;
        for(int i = 0 ; i < A.size() ; i++){
            if(A[i] >= L and A[i] <= R){
                ans = ans + i - index;
                left = i - index;
            }
            if(A[i] > R){
                index = i;
                left = 0;
            }
            if(A[i] < L){
                ans = ans + left;
            }
            cout << ans << " ";
        }
        return ans;
    }
};

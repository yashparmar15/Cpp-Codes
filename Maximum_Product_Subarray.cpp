/*Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/


class Solution {
public:
    int maxProduct(vector<int>& A) {
        int n = A.size();
        if(n==1) return A[0];
        int pMax=0, nMax=0, m = 0;
        for(int i=0; i<n; i++){
            if(A[i]<0) swap(pMax, nMax);
            pMax = max(pMax*A[i], A[i]);
            nMax = min(nMax*A[i], A[i]);
            m = max(m, pMax);
        }
        return m;
    }
};

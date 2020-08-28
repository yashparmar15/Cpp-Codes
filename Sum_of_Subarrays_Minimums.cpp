/*Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000
 */
 
 
 class Solution {
public:
    int M = 1000000007;
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        vector<int> pre(n),next(n);
        stack<int> s1,s2;
        for(int i = 0 ; i < n ; i++){
            next[i] = n - i - 1;
            pre[i] = i;
        }
        for(int i = 0 ; i < n ; i++){
            while(!s1.empty() and A[s1.top()] > A[i]){
                next[s1.top()] = i - s1.top() - 1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            while(!s2.empty() and A[s2.top()] >= A[i]){
                pre[s2.top()] = s2.top() - i - 1;
                s2.pop();
            }
            s2.push(i);
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = (ans%M + ((A[i]%M)*(pre[i] + 1)%M * (next[i] + 1)%M)%M)%M;
        }
        return ans;
    }
};

/*Given an array of integers A, consider all non-empty subsequences of A.

For any sequence S, let the width of S be the difference between the maximum and minimum element of S.

Return the sum of the widths of all subsequences of A. 

As the answer may be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
 

Note:

1 <= A.length <= 20000
1 <= A[i] <= 20000*/


class Solution {
public:
    int M = 1000000007;
    vector<long long> p;
    int sumSubseqWidths(vector<int>& A) {
        int num = 1;
        for(int i = 0 ; i < 20000 ; i++){
            p.push_back(num);
            num = ((num%M)*(2%M))%M;
        }
        sort(A.begin(),A.end());
        int ans = 0;
        int n = A.size() - 1;
        for(int i = 0 ; i < A.size() ; i++){
            int a = n - i;
            ans = ((ans%M) + ((A[i]%M)*(-p[a]%M + p[i]%M)%M)%M)%M;
        }
        return ans%M;
    }
};

/*Given an array A of positive integers (not necessarily distinct), return the lexicographically largest permutation that is smaller than A, that can be made with one swap (A swap exchanges the positions of two numbers A[i] and A[j]).  If it cannot be done, then return the same array.

 

Example 1:

Input: [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.
Example 2:

Input: [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.
Example 3:

Input: [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.
Example 4:

Input: [3,1,1,3]
Output: [1,3,1,3]
Explanation: Swapping 1 and 3.
 

Note:

1 <= A.length <= 10000
1 <= A[i] <= 10000*/


class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        int Min = A[n - 1];
        int num = -1,index = -1;
        for(int i = n - 2 ; i >= 0 ; i--){
            if(A[i] > Min){
                num = A[i];
                index = i;
                break;
            }
            Min = min(A[i],Min);
        }
        if(num == -1 and index == -1) return A;
        int with = -1;
        Min = INT_MAX;
        for(int i = n - 1 ; i > index ; i--){
            if(num - A[i] > 0 and num - A[i] < Min){
                Min = num - A[i];
                with = i;
            }
        }
        swap(A[with],A[index]);
        return A;
    }
};

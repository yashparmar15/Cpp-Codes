/*Given an array A, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

 

Example 1:

Input: [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
 

Note:

2 <= A.length <= 30000
0 <= A[i] <= 10^6
It is guaranteed there is at least one way to partition A as described.*/



class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> left(A.size(),0),right(A.size(),0);
        left[0] = A[0];
        for(int i = 1 ; i < A.size() ; i++)
            left[i] = max(left[i - 1],A[i]);
        right[A.size() - 1] = A[A.size() - 1];
        for(int i = A.size() - 2 ; i >= 0 ; i--)
            right[i] = min(right[i + 1],A[i]);
        for(int i = 0 ; i < A.size() - 1 ; i++)
            if(right[i + 1] >= left[i]) return i + 1;
        return 0;
    }
};

/*Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9*/


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        for(int i = 0 , j = 0 ; i < A.size() and j < B.size() ;){
            int start = max(A[i][0],B[j][0]);
            int end = min(A[i][1],B[j][1]);
            if(start <= end){
                if(start == A[i][0] and end == A[i][1]){
                    if(end <= B[j][1])
                        ans.push_back({start,end});
                    i++;
                } else {
                    if(start == B[j][0] and end == B[j][1]){
                        if(end <= A[i][1])
                            ans.push_back({start,end});
                        j++;
                    } else {
                        ans.push_back({start,end});
                        if(end == A[i][1]) i++;
                        else j++;
                    } 
                }
            } else {
                if(end == A[i][1]) i++;
                else j++;
            }
        }
        return ans;
    }
};

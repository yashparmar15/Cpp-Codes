/*In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the ith domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

 

Example 1:


Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= A.length == B.length <= 2 * 104
1 <= A[i], B[i] <= 6*/


class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<vector<vector<int>>> H(A.size(),vector<vector<int>> (7,vector<int>(2,0)));
        for(int i = 0 ; i < A.size() ; i++){
            H[i][A[i]][0] = 1;
            H[i][B[i]][1] = 1;
        }
        int ans = INT_MAX;
        for(int k = 1 ; k < 7 ; k++){
            int count1 = 0,count2 = 0;
            bool flag1 = true,flag2 = true;
            for(int i = 0 ; i < A.size() ; i++){
                if(H[i][k][0] == 0){
                    if(H[i][k][1] == 0) flag1 = false;
                    else count1++;
                }
                if(H[i][k][1] == 0){
                    if(H[i][k][0] == 0) flag2 = false;
                    else count2++;
                }
                if(!flag1 or !flag2) break;
            }
            if(flag1) ans = min(ans,count1);
            if(flag2) ans = min(ans,count2);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////



class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> countA(7), countB(7), same(7);
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            countA[A[i]]++;
            countB[B[i]]++;
            if (A[i] == B[i])
                same[A[i]]++;
        }
        for (int i  = 1; i < 7; ++i)
            if (countA[i] + countB[i] - same[i] == n)
                return n - max(countA[i], countB[i]);
        return -1;
    }
};

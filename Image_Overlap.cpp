/*Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes: 

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1*/


class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ans = 0;
        int n = A.size();
        for(int i = - n + 1 ; i < n ; i++){
            for(int j = - n + 1 ; j < n ; j++){
                int count = 0;
                for(int k = 0 ; k < n ; k++){
                    for(int l = 0 ; l < n ; l++){
                        if(k + i >= 0 and j + l >= 0 and k + i < n and j + l < n and A[k + i][l + j] == 1 and B[k][l] == 1)
                            count++;
                    }
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};

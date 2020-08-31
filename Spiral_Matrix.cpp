/*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while(bottom>=top && right>=left) {
            for(int j=left; j<=right; j++) res.push_back(matrix[top][j]);
            top++;
            for(int i=top; i<=bottom; i++) res.push_back(matrix[i][right]);
            right--;
            if(top <= bottom) {
                for(int j=right; j>=left; j--) res.push_back(matrix[bottom][j]);
                bottom--;
            }
            if(left <= right) {
                for(int i=bottom; i>=top; i--) res.push_back(matrix[i][left]);
                left++;   
            }
        }
        
        return res;
    }
};

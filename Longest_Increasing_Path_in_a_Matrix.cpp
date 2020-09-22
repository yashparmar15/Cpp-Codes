/*Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.*/


class Solution {
public:
    int ans = 0;
    unordered_map<int,unordered_map<int,int>> M;
    int dfs(vector<vector<int>> &matrix,int i,int j){
        if(i < 0 or j < 0 or i >= matrix.size() or j >= matrix[0].size() or matrix[i][j] == INT_MIN) return 0;
        if(M[i][j]) return M[i][j];
        int up,down,left,right;
        if(i + 1 < matrix.size() and matrix[i + 1][j] > matrix[i][j]) up = dfs(matrix,i+1,j);
        else up = 0;
        if(j + 1 < matrix[0].size() and matrix[i][j + 1] > matrix[i][j]) right = dfs(matrix,i,j+1);
        else right = 0;
        if(i - 1 >= 0 and matrix[i - 1][j] > matrix[i][j]) down = dfs(matrix,i-1,j);
        else down = 0;
        if(j - 1 >= 0 and matrix[i][j - 1] > matrix[i][j]) left = dfs(matrix,i,j-1);
        else left = 0;
        M[i][j] = max(up,max(down,max(right,left))) + 1;
        return M[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                int count = dfs(matrix,i,j);
                ans = max(ans,count);
            }
        }
        return ans;
    }
};

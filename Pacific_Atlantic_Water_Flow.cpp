/*Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:

The order of returned grid coordinates does not matter.
Both m and n are less than 150.
 

Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).*/


class Solution {
public:
    int N,M;
    void dfs(vector<vector<int>> &matrix,vector<vector<int>> &v,int i,int j){
        if(i < 0 or j < 0 or i >= N or j >= M or matrix[i][j] == -1) return;
        v[i][j]++;
        int temp = matrix[i][j];
        matrix[i][j] = -1;
        if(i + 1 < N and matrix[i + 1][j] >= temp)
            dfs(matrix,v,i+1,j);
        if(j + 1 < M and matrix[i][j + 1] >= temp)
            dfs(matrix,v,i,j+1);
        if(i - 1 >= 0 and matrix[i - 1][j] >= temp)
            dfs(matrix,v,i-1,j);
        if(j - 1 >= 0 and matrix[i][j - 1] >= temp)
            dfs(matrix,v,i,j-1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        N = matrix.size();
        if(N == 0)return {};
        M = matrix[0].size();
        vector<vector<int>> v(N,vector<int>(M,0));
        vector<vector<int>> temp = matrix;
        for(int i = 0 ; i < N ; i++)
            if(matrix[i][0] != -1)
                dfs(matrix,v,i,0);
        for(int i = 0 ; i < M ; i++)
            if(matrix[0][i] != -1)
                dfs(matrix,v,0,i);
        matrix = temp;
        for(int i = 0 ; i < N ; i++)
            if(matrix[i][M - 1] != -1)
                dfs(matrix,v,i,M - 1);
        for(int i = 0 ; i < M ; i++)
            if(matrix[N - 1][i] != -1)
                dfs(matrix,v,N - 1,i);
        vector<vector<int>> ans;
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < M ; j++)
                if(v[i][j] == 2) ans.push_back({i,j});
        return ans;
    }
};

/*Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.

 

Example 1:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]
Example 2:


Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
Example 3:

Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 50
1 <= n <= 50
-1000 <= grid[i][j] <= 1000
0 <= k <= 100*/



class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(),m = grid[0].size();
        int sn = k % n,sm = k % m;
        vector<vector<int>> ans = grid;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                ans[i][(j + sm) % m] = grid[i][j];
        grid = ans;
        int rot = k / m,r;
        for(int i = 0 ; i < m ; i++){
            if(i < k % m) r = rot + 1; else r = rot;
            for(int j = 0 ; j < n ; j++)
                ans[(j + r) % n][i] = grid[j][i];
        }
        return ans;
    }
};

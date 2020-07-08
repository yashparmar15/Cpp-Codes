// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

// Example 1:

// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
// Note: The length of each dimension in the given grid does not exceed 50.




class Solution {
public:
    void dfs(vector<vector<int>> &grid,int &count,int x,int y){
        grid[x][y] = 0;
        count++;
        if(x + 1 < grid.size() and grid[x+1][y] == 1)
            dfs(grid,count,x+1,y);
        if(x - 1 >= 0 and grid[x-1][y] == 1)
            dfs(grid,count,x-1,y);
        if(y + 1 < grid[0].size() and grid[x][y+1] == 1)
            dfs(grid,count,x,y+1);
        if(y - 1 >= 0 and grid[x][y-1] == 1) 
            dfs(grid,count,x,y-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    int count = 0;
                    dfs(grid,count,i,j);
                    ans = max(ans,count);
                }
            }
        }
        if(ans == INT_MIN)
            return 0;
        return ans;
    }
};
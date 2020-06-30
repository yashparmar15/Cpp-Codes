// On a 2-dimensional grid, there are 4 types of squares:

// 1 represents the starting square.  There is exactly one starting square.
// 2 represents the ending square.  There is exactly one ending square.
// 0 represents empty squares we can walk over.
// -1 represents obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

// Example 1:

// Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)


class Solution {
public:
    int count = 1;
    void recur(vector<vector<int>> &grid , int &ans,int n , int m , int i , int j){
        if(i >= n or j >= m or i < 0 or j < 0)
            return;
        if(grid[i][j] == 2){
            if(count == 0) ans++;
            return;
        }
        if(grid[i][j] < 0)
            return;
        grid[i][j] = -1;
        count --;
        recur(grid,ans,n,m,i+1,j);
        recur(grid,ans,n,m,i-1,j);
        recur(grid,ans,n,m,i,j+1);
        recur(grid,ans,n,m,i,j-1);
        grid[i][j] = 0;
        count ++;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        int i = 0 , j = 0;
        bool flag = 0;
        for(int k = 0 ; k < n ; k++){
            for(int kk = 0 ; kk < m ; kk++){
                if(grid[k][kk] == 0)
                    count++;
                if(grid[k][kk] == 1){
                    i = k;
                    j = kk;
                }
            }
        }
        recur(grid,ans,n,m,i,j);
        return ans;
    }
};
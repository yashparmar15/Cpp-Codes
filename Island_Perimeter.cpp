// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

// Example:

// Input:
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]

// Output: 16

// Explanation: The perimeter is the 16 yellow stripes in the image below:





class Solution {
public:
    void recur(vector<vector<int>> &grid , int &ans , int x , int y , int n , int m){
        grid[x][y] = -1;
        if(x + 1 < n){
            if(grid[x + 1][y] == 0)
                ans++;
            else
                if(grid[x + 1][y] == 1)
                    recur(grid,ans,x+1,y,n,m);
        } else {
            ans++;
        }
        if(x - 1 >= 0){
            if(grid[x - 1][y] == 0)
                ans++;
            else
                if(grid[x - 1][y] == 1)
                    recur(grid,ans,x-1,y,n,m);
        } else {
            ans++;
        }
        if(y + 1 < m){
            if(grid[x][y + 1] == 0)
                ans++;
            else
                if(grid[x][y + 1] == 1)
                    recur(grid,ans,x,y+1,n,m);
        } else {
            ans++;
        }
        if(y - 1 >= 0){
            if(grid[x][y - 1] == 0)
                ans++;
            else
                if(grid[x][y - 1] == 1)
                    recur(grid,ans,x,y - 1,n,m);
        } else {
            ans++;
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int x = 0 , y = 0;
        bool flag = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        recur(grid,ans,x,y,n,m);
        return ans;
    }
};
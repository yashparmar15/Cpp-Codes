/*In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.*/


class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int count,int x , int y , vector<vector<int>> &cur){
        if(x >= grid.size() or y >= grid[0].size() or x < 0 or y < 0){
            return;
        }
        if(grid[x][y] == 0 or cur[x][y] == 1 or grid[x][y] == 2)
            return;
        cur[x][y] = 1;
        if(grid[x][y] == 1 or grid[x][y] == 3){
            vis[x][y] = min(vis[x][y],count);
            grid[x][y] = 3;
        }
        dfs(grid,vis,count+1, x + 1, y,cur);
        dfs(grid,vis,count+1, x - 1, y,cur);
        dfs(grid,vis,count+1, x, y - 1,cur);
        dfs(grid,vis,count+1, x, y + 1,cur);
        cur[x][y] = 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> vis , cur;
        for(int i = 0 ; i < grid.size() ; i++){
            vector<int> temp(grid[i].size(),1000);
            vector<int> t(grid[i].size(),0);
            cur.push_back(t);
            vis.push_back(temp);
        }
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(grid[i][j] == 2){
                    int count = 0;
                    grid[i][j] = 3;
                    dfs(grid,vis,count,i,j,cur);
                }
            }
        }
        bool check = true;
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                cout << vis[i][j] << " ";
                if(vis[i][j] != 1000)
                    ans = max(ans,vis[i][j]);
                if(grid[i][j] == 1){
                    check = false;
                    break;
                }
            }
            cout << endl;
            if(!check)
                break;
        }
        if(!check)
            return -1;
        return ans;
    }
};

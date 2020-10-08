class Solution {
public:
    bool safe(int x,int y , int n ,int m)
    {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    void dfs(vector<vector<int>> &grid , vector<vector<bool>>& visited,int x , int y , int n , int m)
    {
        if(!safe(x,y,n,m) || visited[x][y] || grid[x][y] == 0)
            return ;
        
        visited[x][y] = true;
        
        dfs(grid,visited,x+1,y,n,m);
        dfs(grid,visited,x-1,y,n,m);
        dfs(grid,visited,x,y+1,n,m);
        dfs(grid,visited,x,y-1,n,m);
    }
    int count_islands(vector<vector<int>>& grid)
    {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n , vector<bool>(m,false));
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    dfs(grid,visited,i,j,n,m);
                    count++;
                }
            }
        }
        
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        
      // dfs..
        int n = grid.size();
        int m = grid[0].size();
        
        int count = count_islands(grid);
        
        if(count > 1)
            return 0; // already disconnected..
        
        // check for 1..
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    
                    grid[i][j] = 0;
                    
                    int count = count_islands(grid);
                    if(count > 1 or count == 0)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};

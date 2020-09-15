class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() == 0) return ans;
        queue<pair<int,int>> q;
        int N = grid.size(), M = grid[0].size();
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(grid[i][j] == 1){
                    q.push(make_pair(i,j));
                    int count = 1;
                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();
                        int x = temp.first,y = temp.second;
                        if(x+1 < N and grid[x+1][y] == 1){
                            q.push(make_pair(x+1,y));
                            grid[x+1][y] = 2;
                            count++;
                        }
                        if(x-1 >= 0 and grid[x-1][y] == 1){
                            q.push(make_pair(x-1,y));
                            grid[x-1][y] = 2;
                            count++;
                        }
                        if(y+1 < M and grid[x][y+1] == 1){
                            q.push(make_pair(x,y+1));
                            grid[x][y+1] = 2;
                            count++;
                        }
                        if(y-1 >= 0 and grid[x][y-1] == 1){
                            q.push(make_pair(x,y-1));
                            grid[x][y-1] = 2;
                            count++;
                        }
                    }
                    ans = max(ans,count - 1);
                    if(count == 1) ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};

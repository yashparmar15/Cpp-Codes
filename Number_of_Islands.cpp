class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        if(grid.size() == 0) return ans;
        queue<pair<int,int>> q;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == '1'){
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        auto temp = q.front();
                        q.pop();
                        grid[temp.first][temp.second] = '2';
                        if(temp.first + 1 < grid.size() and grid[temp.first + 1][temp.second] == '1'){
                            q.push(make_pair(temp.first + 1,temp.second));
                            grid[temp.first + 1][temp.second] = '2';
                        }
                        if(temp.first - 1 >= 0 and grid[temp.first - 1][temp.second] == '1'){
                            q.push(make_pair(temp.first - 1,temp.second));
                            grid[temp.first - 1][temp.second] = '2';
                        }
                        if(temp.second + 1 < grid[0].size() and grid[temp.first][temp.second + 1] == '1'){
                            q.push(make_pair(temp.first,temp.second + 1));
                            grid[temp.first][temp.second + 1] = '2';
                        }
                        if(temp.second - 1 >= 0 and grid[temp.first][temp.second - 1] == '1'){
                            q.push(make_pair(temp.first,temp.second - 1));
                            grid[temp.first][temp.second - 1] = '2';
                        }
                        cout << q.size() << endl;
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};

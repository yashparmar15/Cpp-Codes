/*In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]


Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4

 

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1*/


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));
        queue<pair<int,pair<int,int>>> q;
        if(grid.size() == 0) return 0;
        q.push(make_pair(0,make_pair(0,1)));
        if(grid[0][0] == 1) return -1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second.first;
                if(i == grid.size() - 1 and j == grid[0].size() - 1) return temp.second.second;
                if(vis[i][j] == 0){
                    vis[i][j] = 1;
                    for(int x = -1 ; x <= 1 ; x++){
                        for(int y = -1 ; y <= 1 ; y++){
                            if(x != 0 or y != 0){
                                if(i + x >= 0 and i + x < grid.size() and j + y >= 0 and j + y < grid[0].size() and grid[i + x][j + y] == 0)
                                    q.push(make_pair(i + x,make_pair(j + y,temp.second.second + 1)));
                                    
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};

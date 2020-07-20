/*Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.*/



class Solution {
public:
    // void dfs(vector<vector<int>> &matrix , int x ,int y ,int dis){
    //     if(x < 0 or x >= matrix.size() or y < 0 or y >= matrix[0].size() or dis >= matrix[x][y])
    //         return;
    //     matrix[x][y] = dis;
    //     dis++;
    //     dfs(matrix,x+1,y,dis);
    //     dfs(matrix,x-1,y,dis);
    //     dfs(matrix,x,y+1,dis);
    //     dfs(matrix,x,y-1,dis);
    // }
    // vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     for(int i = 0 ; i < matrix.size() ; i++){   
    //         for(int j = 0 ; j < matrix[0].size() ; j++){
    //             if(matrix[i][j] == 1)
    //                 matrix[i][j] = INT_MAX;
    //         }
    //     }
    //     for(int i = 0 ; i < matrix.size() ; i++){
    //         for(int j = 0 ; j < matrix[0].size() ; j++){
    //             if(matrix[i][j] == 0){
    //                 int dis = 1;
    //                 dfs(matrix,i+1,j,dis);
    //                 dfs(matrix,i-1,j,dis);
    //                 dfs(matrix,i,j+1,dis);
    //                 dfs(matrix,i,j-1,dis);
    //             }
    //         }
    //     }
    //     return matrix;
    // }
    
    struct point{
			int x,y;
	 };

    bool isValid(int row, int col, int ROW, int COL){
        return ((row >= 0) && (row < ROW) && (col >= 0) && (col < COL));
    }

    void BFS(vector<vector<int> > &mat, point src, int &count, int ROW, int COL){
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, -1, 0, 1};
        queue<point>q;
        bool vis[ROW][COL];
        memset(vis, false, sizeof(vis));
        vis[src.x][src.y] = true;
        q.push(src);
        while(!q.empty()){
            int k = q.size();
            while(k--){
                point curr = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int x = curr.x + row[i];
                    int y = curr.y + col[i];
                    if(isValid(x, y, ROW, COL)){
                        if(mat[x][y] == 0){
                            return;
                        }
                        if(mat[x][y]){
                            if(!vis[x][y]){
                                q.push({x, y});
                                vis[x][y] = true;
                            }
                        }
                    }
                }
            }
            count++;   
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0)
                    ans[i][j] = 0;
                else{
                    int count = 1;
                    point ptr = {i,j};
                    BFS(matrix,ptr,count, m,n);
                    ans[i][j] = count;
                }
            }
        }
		return ans;
    }
};

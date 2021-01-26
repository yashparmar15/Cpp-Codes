/*You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106*/



class Solution {
public:
    bool dfs(int i,int j,int &n,int &m,vector<vector<int>> &h,int vis[100][100],int &limit){
        if(i == n - 1 and j == m - 1) return true;
        bool temp = false;
        vis[i][j] = 1;
        if(i - 1 >= 0 and vis[i - 1][j] == 0 and abs(h[i - 1][j] - h[i][j]) <= limit)
            temp = temp or dfs(i - 1,j,n,m,h,vis,limit);
        if(j - 1 >= 0 and vis[i][j - 1] == 0 and abs(h[i][j - 1] - h[i][j]) <= limit)
            temp = temp or dfs(i,j - 1,n,m,h,vis,limit);
        if(j + 1 < m and vis[i][j + 1] == 0 and abs(h[i][j + 1] - h[i][j]) <= limit)
            temp = temp or dfs(i,j + 1,n,m,h,vis,limit);
        if(i + 1 < n and vis[i + 1][j] == 0 and abs(h[i + 1][j] - h[i][j]) <= limit)
            temp = temp or dfs(i + 1,j,n,m,h,vis,limit);
        return temp;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int start = 0,end = 1000000;
        int ans = INT_MAX;
        int vis[100][100];
        while(start <= end){
            int mid = start + (end - start) / 2;
            memset(vis,0,sizeof(vis));
            if(dfs(0,0,n,m,heights,vis,mid)){
                end = mid - 1;
                ans = min(ans,mid);
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

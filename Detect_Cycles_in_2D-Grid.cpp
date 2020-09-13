/*Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.

 

Example 1:



Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:

Example 2:



Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:

Example 3:



Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 500
1 <= n <= 500
grid consists only of lowercase English letters.*/


class Solution {
public:
    void dfs(vector<vector<char>> &v,int i,int j,map<pair<int,int>,int> &M,vector<vector<int>> &vis,int count,bool &isLoop,char &ch,int index){
        if(i < 0 or j < 0 or i >= v.size() or j >= v[0].size() or isLoop) return;
        if(v[i][j] != ch) return;
        if(vis[i][j] and abs(M[make_pair(i,j)] - count) > 3) isLoop = 1;
        if(vis[i][j]) return;
        M[make_pair(i,j)] = count;
        vis[i][j] = 1;
        if(index != 2) dfs(v,i+1,j,M,vis,count + 1,isLoop,ch,1);
        if(index != 1) dfs(v,i-1,j,M,vis,count + 1,isLoop,ch,2);
        if(index != 4) dfs(v,i,j+1,M,vis,count + 1,isLoop,ch,3);
        if(index != 3) dfs(v,i,j-1,M,vis,count + 1,isLoop,ch,4);
    }
    bool containsCycle(vector<vector<char>>& grid) {
        map<pair<int,int>,int> M;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size()));
        for(int i = 0 ; i < grid.size() ; i++)
            for(int j = 0 ; j < grid[0].size() ; j++){
                bool isLoop = false;
                if(vis[i][j] == 0)
                    dfs(grid,i,j,M,vis,0,isLoop,grid[i][j],0);
                if(isLoop) return 1;
            }
        return 0;
    }
};


/////////////////////////////////////////////////////////////////////////////////////////



class Solution {
public:
    int ch;
    bool dfs(vector<vector<pair<int,int>>> &v,int i,int j,int count,int index){
        if(i < 0 or j < 0 or i >= v.size() or j >= v[0].size() or v[i][j].first != ch) return 0;
        if(v[i][j].second){
            if(abs(v[i][j].second - count) > 3) return 1;
            else return 0;
        }
        v[i][j].second = count;
        if(index == 0) return dfs(v,i+1,j,count + 1,1) or dfs(v,i,j+1,count + 1,3) or dfs(v,i,j-1,count + 1,4) or dfs(v,i-1,j,count + 1,2);
        else if(index == 1) return dfs(v,i+1,j,count + 1,1) or dfs(v,i,j+1,count + 1,3) or dfs(v,i,j-1,count + 1,4);
        else if(index == 2) return dfs(v,i-1,j,count + 1,2) or dfs(v,i,j+1,count + 1,3) or dfs(v,i,j-1,count + 1,4);
        else if(index == 3) return dfs(v,i+1,j,count + 1,1) or dfs(v,i-1,j,count + 1,2) or dfs(v,i,j+1,count + 1,3);
        else return dfs(v,i+1,j,count + 1,1) or dfs(v,i-1,j,count + 1,2) or dfs(v,i,j-1,count + 1,4);
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<pair<int,int>>> v(grid.size(),vector<pair<int,int>> (grid[0].size(),make_pair(0,0)));
        vector<int> H(26,0);
        for(int i = 0 ; i < grid.size() ; i++)
            for(int j = 0 ; j < grid[0].size() ; j++){
                v[i][j].first = int(grid[i][j]);
                H[v[i][j].first - 97]++;
            }
        for(int i = 0 ; i < grid.size() ; i++)
            for(int j = 0 ; j < grid[0].size() ; j++){
                ch = v[i][j].first;
                if(v[i][j].second == 0 and H[ch - 97] >= 4){
                    if(dfs(v,i,j,1,0))
                        return 1;
                }
            }
        return 0;
    }
};


/*Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.*/




class Solution {
public:
    void dfs(vector<vector<char>> &v,int i,int j){
        if(i < 0 or j < 0 or i >= v.size() or j >= v[0].size() or v[i][j] != 'O') return;
        v[i][j] = 'Y';
        dfs(v,i+1,j);
        dfs(v,i-1,j);
        dfs(v,i,j-1);
        dfs(v,i,j+1);
    }
    void solve(vector<vector<char>>& v) {
        if(v.size() == 0) return;
        for(int i = 0 ; i < v[0].size() ; i++)
            if(v[0][i] == 'O')
                dfs(v,0,i);
        for(int i = 0 ; i < v.size() ; i++)
            if(v[i][0] == 'O')
                dfs(v,i,0);
        for(int i = 0 ; i < v[0].size() ; i++)
            if(v[v.size() - 1][i] == 'O')
                dfs(v,v.size() - 1,i);
        for(int i = 0 ; i < v.size() ; i++)
            if(v[i][v[0].size() - 1] == 'O')
                dfs(v,i,v[0].size() - 1);
        for(int i = 0 ; i < v.size() ; i++)
            for(int j = 0 ; j < v[0].size() ; j++)
                if(v[i][j] == 'Y') v[i][j] = 'O';
                else v[i][j] = 'X';
    }
};

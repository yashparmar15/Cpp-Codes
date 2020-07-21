/*Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3*/


class Solution {
public:
   bool dfs(int x, int y, vector<vector<char>>& b, string& w, int p){
        if(x<0 || y<0 || x >=b.size() || y>=b[0].size() || b[x][y] != w[p]) return false;
        if(p == w.size()-1) return true;
        char t = b[x][y];
        b[x][y]='0';
        bool check = dfs(x+1,y,b,w,p+1) || dfs(x-1,y,b,w,p+1) || dfs(x,y-1,b,w,p+1) || dfs(x,y+1,b,w,p+1);
        b[x][y]=t;
        return check;
    }
    bool exist(vector<vector<char>>& b, string w) {
        int n = b.size(), m = b[0].size();
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(dfs(i,j,b,w,0)) return true;
        return false;
    }
};

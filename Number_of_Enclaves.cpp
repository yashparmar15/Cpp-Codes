/*Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)

A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.

Return the number of land squares in the grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:

Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: 
There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed because its on the boundary.
Example 2:

Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: 
All 1s are either on the boundary or can reach the boundary.
 

Note:

1 <= A.length <= 500
1 <= A[i].length <= 500
0 <= A[i][j] <= 1
All rows have the same size.*/


class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>> &A,int &count,bool &flag,int i,int j){
        if(i < 0 or j < 0 or i >= A.size() or j >= A[0].size())
            return;
        if(A[i][j] != 1) return;
        if(i + 1 < A.size() and i - 1 >= 0 and j + 1 < A[0].size() and j - 1 >= 0){
            count++;
            A[i][j] = 0;
            dfs(A,count,flag,i+1,j);
            dfs(A,count,flag,i-1,j);
            dfs(A,count,flag,i,j+1);
            dfs(A,count,flag,i,j-1);
        }
        else{
            flag = false;
        }
    }
    int numEnclaves(vector<vector<int>>& A) {
        int count = 0;
        for(int i = 0 ; i < A.size() ; i++){
            for(int j = 0 ; j < A[0].size() ; j++){
                if(A[i][j] == 1){
                    int count = 0;
                    bool flag = true;
                    dfs(A,count,flag,i,j);
                    if(flag) ans += count;
                }
            }
        }
        return ans;
    }
};

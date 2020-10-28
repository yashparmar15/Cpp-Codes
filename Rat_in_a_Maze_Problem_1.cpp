/*Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (N-1, N-1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be traveled through.

Example 1:

Input: N = 4, m[][] = {{1, 0, 0, 0},
                       {1, 1, 0, 1}, 
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}}
Output: DDRDRR DRDDRR
Explanation: The rat can reach the 
destination at (3, 3) from (0, 0) by two 
paths ie DRDDRR and DDRDRR when printed 
in sorted order we get DDRDRR DRDDRR.
Example 2:
Input: N = 2, m[][] = {{1, 0},
                       {1, 0}}
Output: -1
Explanation: No path exits

Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2d array m[][] as input parameters and returns a sorted list of paths.
 
Note:  In case of no path, return an empty list. The driver will output -1 automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L*X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1*/


void dfs(vector<string> &ans,string temp,int i,int j,int &n,vector<vector<int>> &arr){
    if(i == n - 1 and j == n - 1){
        ans.push_back(temp);
        return;
    }
    if(i < 0 or j < 0 or i >= n or j >= n or arr[i][j] == 0) return;
    arr[i][j] = 0;
    dfs(ans,temp + "D",i+1,j,n,arr);
    dfs(ans,temp + "U",i-1,j,n,arr);
    dfs(ans,temp + "R",i,j+1,n,arr);
    dfs(ans,temp + "L",i,j-1,n,arr);
    arr[i][j] = 1;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            arr[i][j] = m[i][j];
    vector<string> ans;
    if(m[0][0] == 0 or m[n - 1][n - 1] == 0) return ans;
    string temp = "";
    dfs(ans,temp,0,0,n,arr);
    sort(ans.begin(),ans.end());
    return ans;
}

/*There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

 

Example 1:

Input: m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:

Example 2:

Input: m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:

 

Note:

Once you move the ball out of boundary, you cannot move it back.
The length and height of the grid is in range [1,50].
N is in range [0,50].*/


class Solution {
public:
    int M = 1000000007;
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> M;
        vector<int> t1(N + 1,-1);
        vector<vector<int>> t2;
        for(int i = 0 ; i < n ; i++)
            t2.push_back(t1);
        for(int i = 0 ; i < m ; i++)
            M.push_back(t2);
        return findPath(m,n,N,i,j,M);
    }
    int findPath(int &m, int &n, int N, int i, int j, vector<vector<vector<int>>>& memo) {
    if (i == m || j == n || i < 0 || j < 0) return 1;
    if (N == 0) return 0;
    if (memo[i][j][N] >= 0) return memo[i][j][N];
    memo[i][j][N] = (
        (findPath(m, n, N - 1, i - 1, j, memo) + findPath(m, n, N - 1, i + 1, j, memo)) % M +
        (findPath(m, n, N - 1, i, j - 1, memo) + findPath(m, n, N - 1, i, j + 1, memo)) % M
    ) % M;
    return memo[i][j][N];
  }
};
